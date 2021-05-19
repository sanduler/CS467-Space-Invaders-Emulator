#include "SI_GameLoop.h"
#include <cstdlib>

extern SDL_Window* gameWindow;
extern SDL_Renderer* gwRenderer;
extern SDL_Texture* siContainer;
extern SDL_Texture* siBackground;

extern i8080_CPU i8080;
extern const int EM_WIDTH;
extern const int EM_HEIGHT;

void SI_GameLoop()
{
	// flag to signal space invaders exit
	bool quit_flag = false;

	// interrupt counter to check if screen update is needed 
	// only call the update if == 1
	int middle_interrupt = false;

	// keep track of the game time to keep the screen updates consistent
	int game_timer = 0;

	// enter while loop until quit signal
	while (!quit_flag) {

		// Reset Inputs
		SI_ResetInputs();

		// handle input by the user
		SI_handleUserInput(quit_flag);

		// For Debugging Only
		/*if (i8080.state.reg_PC.get_Large() == 0x19E3) {
			system("pause");
		}*/

		// execute the opcode
		SI_handleExecuteOpCode();

		// MW moved bit shift ing code into op code handler for time testing
		//if ((i8080.state.opCode_Array[0] == 0xD3) && (i8080.state.opCode_Array[1] == 0x04)) {
		//	SI_16BitShiftRegister();
		//}

		// handle the update to the screen
		// only do this 1/60 seconds by looking at the SDL ticks 
		// if the current SDL ticks (which are returned in ms) is greater than 60 Hz
		if (SDL_GetTicks() - game_timer	> (1000/60)) {
			// reset the game timer so the next instance can be caught
			game_timer = SDL_GetTicks();
			// if on the middle interrupt then do not call update
			// but still send the interrupt
			if (middle_interrupt) {
				i8080.state.SendInterrupt(1);
			} 
			// if on the final interrupt then update screen
			// but call the interrupt first
			else {
				i8080.state.SendInterrupt(2);
				SI_handleScreenUpdate();
			}
			//system("pause");
		}
	}
}

SI_INPUT getUserInput(SDL_Event &evnt)
{
	SI_INPUT return_action = SI_INPUT::NO_ACTION;

	// handle the case where the user has hit the "X"
	if (evnt.type == SDL_QUIT) {
		return_action = SI_INPUT::QUIT;
	}
	// handle the case where the user presses a key
	else if (evnt.type == SDL_KEYDOWN) {
		// evaluate the case based on the keypressed
		switch (evnt.key.keysym.sym) {
		case SDLK_q:
			// User has opted to quit so set the quit flag
			return_action = SI_INPUT::QUIT;
			break;

			// cases where player 1 starts
		case SDLK_s:
			return_action = SI_INPUT::P1_START;
			break;

			// cases where player 2 starts
		case SDLK_k:
			return_action = SI_INPUT::P2_START;
			break;

			// cases where a left move is made
		case SDLK_a:
			return_action = SI_INPUT::P1_MOVE_LEFT;
			break;
		case SDLK_LEFT:
			return_action = SI_INPUT::P1_MOVE_LEFT;
			break;
			// cases where a right move is made
		case SDLK_d:
			return_action = SI_INPUT::P1_MOVE_RIGHT;
			break;
		case SDLK_RIGHT:
			return_action = SI_INPUT::P1_MOVE_RIGHT;
			break;
			// cases where the fire button is pressed
		case SDLK_w:
			return_action = SI_INPUT::P1_FIRE;
			break;
		case SDLK_SPACE:
			return_action = SI_INPUT::P1_FIRE;
			break;
		case SDLK_c:
			return_action = SI_INPUT::INSERT_COIN;
			break;
		default:
			break;
		}
	}
	// handle joystick motion case
	else if (evnt.type == SDL_JOYAXISMOTION) {
		// look for motion on the controller 0
		if (evnt.jaxis.which == 0) {
			// look for x axis motion left
			if (evnt.jaxis.value < -JOYSTICK_DEAD_ZONE) {
				return_action = SI_INPUT::P1_MOVE_LEFT;
			}
			// look for y axis motion right
			else if (evnt.jaxis.value > JOYSTICK_DEAD_ZONE) {
				return_action = SI_INPUT::P1_MOVE_RIGHT;
			}
		}
	}
	// handle joystick button down
	else if (evnt.type == SDL_JOYBUTTONDOWN) {
		switch (evnt.jbutton.button) {
		// A button
		case 0: 
			return_action = SI_INPUT::P1_FIRE;
			break;
		// R middle button
		case 6: 
			return_action = SI_INPUT::QUIT;
			break;
		// L middle button
		case 7: 
			return_action = SI_INPUT::INSERT_COIN; 
			break;
		}
	}
	
	return return_action;
}

void SI_handleUserInput(bool &quit_flag)
{
	// event to handle 
	SDL_Event evnt;

	// look at the event queue and handle events on it until
	// there are none left to handle (the queue is empty)
	while (SDL_PollEvent(&evnt) != 0) {
		// get the user action converted into an enum value 
		switch (getUserInput(evnt)) {
		case SI_INPUT::QUIT:
			printf("QUIT\n");
			quit_flag = true;
			break;
		case SI_INPUT::P1_MOVE_LEFT:
			i8080.state.inputs[1] = i8080.state.inputs[1] | 0x20;
			i8080.state.move_left();
			break;
		case SI_INPUT::P1_MOVE_RIGHT:
			i8080.state.inputs[1] = i8080.state.inputs[1] | 0x40;
			i8080.state.move_right();
			break;
		case SI_INPUT::P1_FIRE:
			i8080.state.inputs[1] = i8080.state.inputs[1] | 0x10;
			i8080.state.fire();
			break;
		case SI_INPUT::INSERT_COIN:
			//printf("PreInputs: %4X\n", i8080.state.inputs[1]);
			i8080.state.inputs[1] = i8080.state.inputs[1] | 0x01;
			i8080.state.insert_coin();
			//printf("PostInputs: %4X\n", i8080.state.inputs[1]);
			//system("pause");
			break;
		case SI_INPUT::P2_MOVE_LEFT:
			i8080.state.inputs[1] = i8080.state.inputs[2] | 0x20;
			i8080.state.move_left();
			break;
		case SI_INPUT::P2_MOVE_RIGHT:
			i8080.state.inputs[1] = i8080.state.inputs[2] | 0x40;
			i8080.state.move_right();
			break;
		case SI_INPUT::P2_FIRE:
			i8080.state.inputs[1] = i8080.state.inputs[2] | 0x10;
			i8080.state.fire();
			break;
		case SI_INPUT::P1_START:
			//printf("PreInputs: %4X\n", i8080.state.inputs[1]);
			i8080.state.inputs[1] = i8080.state.inputs[1] | 0x04;
			printf("Player 1 Start\n");
			//printf("PostInputs: %4X\n", i8080.state.inputs[1]);
			//system("pause");
			break;
		case SI_INPUT::P2_START:
			//printf("PreInputs: %4X\n", i8080.state.inputs[1]);
			i8080.state.inputs[1] = i8080.state.inputs[1] | 0x02;
			printf("Player 2 Start\n");
			//printf("PostInputs: %4X\n", i8080.state.inputs[1]);
			//system("pause");
			break;
		default: break;
		}
	}
}

void SI_handleScreenUpdate()
{
	// define the area for the emulator ontop of the bezel
	const SDL_Rect fillRect = {	165,181,224,256 };

	//int numofbytes = SDL_BYTESPERPIXEL(SDL_PIXELFORMAT_RGBA4444);

	// update the screen pixels (the VRAM)
	i8080.state.load_screen_update();

	// re render the screen
	// apply the updated VRAM to the screen
	//SDL_UpdateTexture(siContainer, NULL, i8080.state.video_RAM, 28 * 224);	// MM Modified this to 28 from 4 Hardware description states 28
	SDL_UpdateTexture(siContainer, NULL, i8080.state.video_RAM, 4 * 224);
	// clear the old renderer
	SDL_RenderClear(gwRenderer);
	// re apply the background bezel
	SDL_RenderCopy(gwRenderer, siBackground, NULL, NULL);
	// apply the si container to the background
	SDL_RenderCopy(gwRenderer, siContainer, NULL, &fillRect);
	// display the screen
	SDL_RenderPresent(gwRenderer);
}

void SI_handleExecuteOpCode()
{
	

	i8080.state.exe_OpCode();

	if ((i8080.state.opCode_Array[0] == 0xD3) && (i8080.state.opCode_Array[1] == 0x04)) {
		SI_16BitShiftRegister();
	}
}

void SI_ResetInputs()
{
	// Initializing Inputs
	// https://computerarcheology.com/Arcade/SpaceInvaders/Hardware.html
	// Port 0
	//		bit 0 DIP4(Seems to be self - test - request read at power up)
	//		bit 1 Always 1
	//		bit 2 Always 1
	//		bit 3 Always 1
	//		bit 4 Fire
	//		bit 5 Left
	//		bit 6 Right
	//		bit 7 ? tied to demux port 7 ?
	i8080.state.inputs[0] = 0x0E;

	// Port 1
	//		bit 0 = CREDIT(1 if deposit)
	//		bit 1 = 2P start(1 if pressed)
	//		bit 2 = 1P start(1 if pressed)
	//		bit 3 = Always 1
	//		bit 4 = 1P shot(1 if pressed)
	//		bit 5 = 1P left(1 if pressed)
	//		bit 6 = 1P right(1 if pressed)
	//		bit 7 = Not connected
	i8080.state.inputs[1] = 0x08;

	// Port 2
	//		bit 0 = DIP3 00 = 3 ships  10 = 5 ships
	//		bit 1 = DIP5 01 = 4 ships  11 = 6 ships
	//		bit 2 = Tilt
	//		bit 3 = DIP6 0 = extra ship at 1500, 1 = extra ship at 1000
	//		bit 4 = P2 shot(1 if pressed)
	//		bit 5 = P2 left(1 if pressed)
	//		bit 6 = P2 right(1 if pressed)
	//		bit 7 = DIP7 Coin info displayed in demo screen 0 = ON
	i8080.state.inputs[2] = 0x0B;

	//Port 3
	//		bit 0 - 7 Shift register data
	//i8080.state.inputs[3] = 0x00;
}

void SI_16BitShiftRegister()
{
	// https://computerarcheology.com/Arcade/SpaceInvaders/Hardware.html
	//f              0	bit
	//	xxxxxxxxyyyyyyyy

	//	Writing to port 4 shifts x into y, and the new value into x, eg.
	//	$0000,
	//	write $aa->$aa00,
	//	write $ff->$ffaa,
	//	write $12->$12ff, ..
	//printf("PreShiftRegister: %4X\n", i8080.state.shiftRegister);
	uint16_t uint16_InitialShiftRegister = i8080.state.shiftRegister;
	uint16_t uint16_ShiftRegisterTemp = 0x0000;
	uint8_t uint8_ShiftLow = 0x00;
	uint8_t uint8_ShiftHigh = 0x00;

	uint8_ShiftLow = uint8_ShiftLow | uint16_InitialShiftRegister;
	uint8_ShiftHigh = uint8_ShiftHigh | (uint16_InitialShiftRegister >> 8);

	uint16_ShiftRegisterTemp = uint16_ShiftRegisterTemp | i8080.state.outputs[4];
	uint16_ShiftRegisterTemp = uint16_ShiftRegisterTemp << 0x08;
	uint16_ShiftRegisterTemp = uint16_ShiftRegisterTemp | uint8_ShiftHigh;
		
	//i8080.state.shiftRegister & 0x00FF;
	//i8080.state.shiftRegister = i8080.state.shiftRegister >> 0x0008;
	//i8080.state.shiftRegister = i8080.state.outputs[4] | 0x0000;
	//printf("PostShiftRegister: %4X\n", i8080.state.shiftRegister);


	//	Writing to port 2 (bits 0, 1, 2) sets the offset for the 8 bit result, eg.
	//	offset 0:
	//rrrrrrrr		result = xxxxxxxx
	//	xxxxxxxxyyyyyyyy
	//printf("PreInput[3]: %4X\n", i8080.state.inputs[3]);
	uint8_t uint8_Offset = i8080.state.outputs[2] & 0x07;
	uint8_t uint8_RegisterTemp = 0x00;
	//printf("Offset: %4X\n", uint8_Offset);

	if (uint8_Offset == 0x00) {
		uint8_RegisterTemp = i8080.state.shiftRegister >> 0x08;
	}

	//	offset 2 :
	//	rrrrrrrr	result = xxxxxxyy
	//	xxxxxxxxyyyyyyyy
	if (uint8_Offset == 0x02) {
		uint8_RegisterTemp = i8080.state.shiftRegister >> 0x06;
	}

	//	offset 7 :
	//	rrrrrrrr	result = xyyyyyyy
	//	xxxxxxxxyyyyyyyy
	if (uint8_Offset == 0x07) {
		uint8_RegisterTemp = i8080.state.shiftRegister >> 0x01;
	}

	i8080.state.inputs[3] = uint8_RegisterTemp;
	//printf("PostInput[3]: %4X\n", i8080.state.inputs[3]);

	//	Reading from port 3 returns said result.
	//system("pause");
}

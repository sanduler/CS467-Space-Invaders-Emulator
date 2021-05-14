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

	// enter while loop until quit signal
	while (!quit_flag) {

		// handle input by the user
		SI_handleUserInput(quit_flag);

		// execute the opcode
		SI_handleExecuteOpCode();

		// handle the update to the screen
		// only do this 1/60 seconds
		if (i8080.state.clock_cycles > 120) {
			// reset the clock cycles when this occurs so we can catch it again
			i8080.state.clock_cycles = 0;
			// if on the middle interrupt then do not call update
			// but still send the interrupt
			if (middle_interrupt) {
				i8080.state.SendInterrupt(8);
			} 
			// if on the final interrupt then update screen
			// but call the interrupt first
			else {
				i8080.state.SendInterrupt(10);
				SI_handleScreenUpdate();
			}
			system("pause");
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
			// cases where a left move is made
		case SDLK_a:
		case SDLK_LEFT:
			return_action = SI_INPUT::MOVE_LEFT;
			break;
			// cases where a right move is made
		case SDLK_d:
		case SDLK_RIGHT:
			return_action = SI_INPUT::MOVE_RIGHT;
			break;
			// cases where the fire button is pressed
		case SDLK_w:
		case SDLK_SPACE:
			return_action = SI_INPUT::FIRE;
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
				return_action = SI_INPUT::MOVE_LEFT;
			}
			// look for y axis motion right
			else if (evnt.jaxis.value > JOYSTICK_DEAD_ZONE) {
				return_action = SI_INPUT::MOVE_RIGHT;
			}
		}
	}
	// handle joystick button down
	else if (evnt.type == SDL_JOYBUTTONDOWN) {
		switch (evnt.jbutton.button) {
		// A button
		case 0: 
			return_action = SI_INPUT::FIRE;
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
		case SI_INPUT::MOVE_LEFT:
			i8080.state.move_left();
			break;
		case SI_INPUT::MOVE_RIGHT:
			i8080.state.move_right();
			break;
		case SI_INPUT::FIRE:
			i8080.state.fire();
			break;
		case SI_INPUT::INSERT_COIN:
			i8080.state.insert_coin();
			break;
		default: break;
		}
	}
}

void SI_handleScreenUpdate()
{
	// define the area for the emulator ontop of the bezel
	const SDL_Rect fillRect = {	165,181,224,256 };

	// update the screen pixels (the VRAM)
	i8080.state.load_screen_update();

	// re render the screen
	// apply the updated VRAM to the screen
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
}

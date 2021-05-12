#include "SI_GameLoop.h"

extern SDL_Window* gameWindow;
extern SDL_Renderer* gwRenderer;

i8080_CPU i8080;

void SI_GameLoop(SDL_Texture* siContainer)
{
	// flag to signal space invaders exit
	bool quit_flag = false;

	// enter while loop until quit signal
	while (!quit_flag) {

		// handle input by the user
		SI_handleUserInput(quit_flag);

		SI_handleScreenUpdate(siContainer);
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

void SI_handleScreenUpdate(SDL_Texture* siContainer)
{
	// get the video memory array from the processor
	
	// draw the array to the rectangle
	
	// START TEST CODE FOR EMULATOR WINDOW *************************
	// define the area for the si emulator
	const SDL_Rect fillRect = {	165,181,224,256 };

	unsigned int* pixels;
	//unsigned char pixels[224 * 256];

	//pixels = (unsigned int*)malloc(224 * 256 * 4);
	//memset(pixels, 255, 224 * 256 * 4);
	pixels = (unsigned int*)malloc(224 * 256);
	memset(pixels, 255, 224 * 256);

	//for (int i = 0; i < 224 * 256 * 4; i++) {
	//	if (i > 224*4) {
	//		pixels[i] = 255;
	//	}
	//	else {
	//		pixels[i] = 100;
	//	}
	//}

	//int pitch;
	//SDL_LockTexture(siContainer, NULL, (void**)&pixels, &pitch);
	////SDL_LockTexture(siContainer, &fillRect, (void**)&pixels, &pitch);
	//// set pixels to solid white
	//for (int i = 0; i < pitch * 256; i++) {
	//	if (i > 224*4) {
	//		pixels[i] = 255;
	//	}
	//	else {
	//		pixels[i] = 100;
	//	}
	//}

	//SDL_UnlockTexture(siContainer);

	// END TEST CODE FOR EMULATOR WINDOW ***************************

	// re render the screen
	SDL_UpdateTexture(siContainer, NULL, pixels, 224);
	SDL_RenderCopy(gwRenderer, siContainer, NULL, &fillRect);
	SDL_RenderPresent(gwRenderer);
	free(pixels);
}

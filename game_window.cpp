#include "SDL.h"
#include <stdio.h>
#include <string>
#include <math.h> 

// window dimensions 
// based on the SI bezel (387 : 400)
const double BEZEL_RATIO = 1.4;

// warnings turned off becuase rounding is OK here
#pragma warning(disable:4244)
const int WIND_WIDTH  = 387 * BEZEL_RATIO;
const int WIND_HEIGHT = 400 * BEZEL_RATIO;
#pragma warning(default:4244)

// emulator window dimensions
// based on the SI ROM (7 : 8)
const int EM_WIDTH = 224;
const int EM_HEIGHT = 256;

// global SDL variables
SDL_Window* gameWindow = NULL;			// main window for game
SDL_Renderer* gwRenderer = NULL;		// main renderer

// function prototypes
bool initGameWindow();					// initializes the game window
void waitForMenuEvent();				// wait for the user to make a selection 
void menuAnimation(bool destroy_flag);	// handle the main menu animation
void runSpaceInvaders();				// run the emulator for space invaders
void closeGameWindow();					// shut down procedure for the game

int main(int argc, char* argv[])
{
	initGameWindow();					// initialize the SDL structures
	waitForMenuEvent();					// wait for the user to select a menu option
	closeGameWindow();					// close the window
	return 0;
}

/*
	Initialize the game window and the game renderer
*/
bool initGameWindow()
{
	bool load_success = true;

	// initialize all SDL attributes
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		printf("Error initGameWindow [init] Error Message: %s\n", SDL_GetError());
		load_success = false;
	}
	else {
		// create the game window
		// SDL_Window = struct that holds info about the window itself
		gameWindow = SDL_CreateWindow(
			"8080 Emulator",			// title of the window
			SDL_WINDOWPOS_CENTERED,		// x pos of window on screen
			SDL_WINDOWPOS_CENTERED,		// y pos of window on screen
			WIND_WIDTH,					// width of window
			WIND_HEIGHT,				// height of window
			SDL_WINDOW_SHOWN			// flag to show window when created
		);
		// check that the window was successfully created before moving on
		if (gameWindow == NULL) {
			printf("Error initGameWindow [window] Error Message: %s\n", SDL_GetError());
			load_success = false;
		}

		// initialize the renderer for the game window
		gwRenderer = SDL_CreateRenderer(gameWindow, -1, SDL_RENDERER_ACCELERATED);
		// check for successful creation of the renderer
		if (gwRenderer == NULL) {
			printf("Error initGameWindow [rendere] Error Message: %s\n", SDL_GetError());
			load_success = false;
		}
	}
	return load_success;
}

/*
	Wait for user to make a selection from the menu
	- While waiting, animate the menu
*/
void waitForMenuEvent()
{
	// flag to signal program exit
	bool quit_flag = false;

	// event to handle 
	SDL_Event evnt;

	while (!quit_flag) {
		// look at the event queue and handle events on it until
		// there are none left to handle (the queue is empty)
		while (SDL_PollEvent(&evnt) != 0) {
			// handle the case where the user has hit the "X"
			if (evnt.type == SDL_QUIT) {
				quit_flag = true;
			}
			// handle the case where the user presses a key
			else if (evnt.type == SDL_KEYDOWN) {
				// evaluate the case based on the keypressed
				switch (evnt.key.keysym.sym) {
				case SDLK_q:
					// User has opted to quit so set the quit flag
					quit_flag = true;
					break;
				case SDLK_c:
					runSpaceInvaders();
					break;
				default:
					break;
				}
			}
		}
		// after the events have been handled switch to the next screen
		menuAnimation(false);		
		SDL_Delay(200);
	}
	// destory the menu textures
	menuAnimation(true);
}

/*
	Handle the menu animation by switching between BMP files
*/
void menuAnimation(bool destroy_flag)
{
	// declare the static variables curresponding to the textures loaded
	static SDL_Texture* gwMenu_1 = NULL;
	static SDL_Texture* gwMenu_2 = NULL;
	static SDL_Texture* gwMenu_3 = NULL;

	// check if the images need to be loaded and if so load them
	if (gwMenu_1 == NULL) {
		SDL_Surface* imageLoader = SDL_LoadBMP("bmp_files/menu_1.bmp");
		gwMenu_1 = SDL_CreateTextureFromSurface(gwRenderer, imageLoader);
		imageLoader = SDL_LoadBMP("bmp_files/menu_2.bmp");
		gwMenu_2 = SDL_CreateTextureFromSurface(gwRenderer, imageLoader);
		imageLoader = SDL_LoadBMP("bmp_files/menu_3.bmp");
		gwMenu_3 = SDL_CreateTextureFromSurface(gwRenderer, imageLoader);
		SDL_FreeSurface(imageLoader);
	}

	// keeps track of the current background image of the menu
	static int cur_menu_ind = 1;

	switch (cur_menu_ind) {
	case 1:
		SDL_RenderCopy(gwRenderer, gwMenu_2, NULL, NULL);
		cur_menu_ind++;
		break;
	case 2:
		SDL_RenderCopy(gwRenderer, gwMenu_3, NULL, NULL);
		cur_menu_ind++;
		break;
	case 3:
		SDL_RenderCopy(gwRenderer, gwMenu_1, NULL, NULL);
		cur_menu_ind = 1;
		break;
	}

	SDL_RenderPresent(gwRenderer);

	// check if the destroy flag is set, if it is destroy the textures
	if (destroy_flag) {
		SDL_DestroyTexture(gwMenu_1);
		gwMenu_1 = NULL;
		SDL_DestroyTexture(gwMenu_2);
		gwMenu_2 = NULL;
		SDL_DestroyTexture(gwMenu_3);
		gwMenu_3 = NULL;
	}

}

/*
	Run the space invaders emulator
	This is the main loop the update function should be called from
*/
void runSpaceInvaders()
{
	// flag to signal program exit
	bool quit_flag = false;

	// event to handle 
	SDL_Event evnt;

	// load the emulator bezel as a texture
	SDL_Surface* siBezel = SDL_LoadBMP("bmp_files/space_invaders_bezel.bmp");
	SDL_Texture* siBackground = SDL_CreateTextureFromSurface(gwRenderer, siBezel);

	// create a texture to run the emulator inside of 
	SDL_Texture* siContainer = SDL_CreateTexture(
		gwRenderer,
		SDL_PIXELFORMAT_RGBA8888,
		SDL_TEXTUREACCESS_STREAMING,
		EM_WIDTH,
		EM_HEIGHT);

	// START TEST CODE FOR EMULATOR WINDOW *************************
	// change all the pixels to white 
	unsigned char* pixels;
	int pitch;
	SDL_LockTexture(siContainer, NULL, (void**)&pixels, &pitch);
	// set pixels to solid white
	for (int i = 0; i < pitch * EM_HEIGHT; i++) {
		pixels[i] = 255;
	}
	SDL_UnlockTexture(siContainer);
	// END TEST CODE FOR EMULATOR WINDOW ***************************

	// define the area for the si emulator
	#pragma warning(disable:4838)
	#pragma warning(disable:4244)
	SDL_Rect fillRect = {
		(WIND_WIDTH / 2) - (EM_WIDTH / 2),
		WIND_HEIGHT / 3.1,
		EM_WIDTH,
		EM_HEIGHT 
	};
	#pragma warning(default:4838)
	#pragma warning(default:4244)

	// enter while loop until quit signal
	while (!quit_flag) {
		// look at the event queue and handle events on it until
		// there are none left to handle (the queue is empty)
		while (SDL_PollEvent(&evnt) != 0) {
			// handle the case where the user has hit the "X"
			if (evnt.type == SDL_QUIT) {
				quit_flag = true;
			}
			// handle the case where the user presses a key
			else if (evnt.type == SDL_KEYDOWN) {
				// evaluate the case based on the keypressed
				switch (evnt.key.keysym.sym) {
				case SDLK_q:
					// User has opted to quit so set the quit flag
					quit_flag = true;
					break;
				default:
					break;
				}
			}
		}
		// after handling the events re render the screen
		SDL_RenderCopy(gwRenderer, siBackground, NULL, NULL);
		SDL_RenderCopy(gwRenderer, siContainer, NULL, &fillRect);
		SDL_RenderPresent(gwRenderer);
	}

	// clean up the SDL structures used for the emulator
	SDL_DestroyTexture(siContainer);
	SDL_DestroyTexture(siBackground);
	SDL_FreeSurface(siBezel);
}

/*
	Free the global variables and quit SDL
*/
void closeGameWindow()
{
	// release the window variable
	SDL_DestroyWindow(gameWindow);
	gameWindow = NULL;

	// Destroy the renderer
	SDL_DestroyRenderer(gwRenderer);
	gwRenderer = NULL;

	// close all SDL processes
	SDL_Quit();
}

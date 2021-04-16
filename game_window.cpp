#include "SDL.h"
#include <stdio.h>
#include <string>

// window dimensions
const int WIND_WIDTH  = 1161;
const int WIND_HEIGHT = 1200;

// emulator window dimensions
const int EM_WIDTH = 224;
const int EM_HEIGHT = 256;

// global SDL variables
SDL_Window* gameWindow = NULL;		// main window for game
SDL_Surface* gwSurface = NULL;		// surface of the game window
SDL_Renderer* gwRenderer   = NULL;
SDL_Surface* gwMenu_1  = NULL;
SDL_Surface* gwMenu_2  = NULL;
SDL_Surface* gwMenu_3  = NULL;

// function prototypes
bool initGameWindow();	// initializes the game window
void loadMainMenu();	// load the main menu files
void waitForMenuEvent();// wait for the user to make a selection 
void runSpaceInvaders();// run the emulator
void closeGameWindow();	// shut down procedure for the game

int main(int argc, char* argv[])
{
	initGameWindow();	// initialize the SDL structures
	loadMainMenu();		// load the menu options
	waitForMenuEvent();	// wait for the user to select a menu option
	closeGameWindow();	// close the window
	return 0;
}

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
		else {
			// get the surface variable of the window created
			gwSurface = SDL_GetWindowSurface(gameWindow);
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

void loadMainMenu()
{


	return;
}

void waitForMenuEvent()
{
	// flag to signal program exit
	bool quit_flag = false;

	// keeps track of the current background image of the menu
	int cur_menu_ind = 1;

	// event to handle 
	SDL_Event evnt;

	// load the menu BG files
	gwMenu_1 = SDL_LoadBMP("bmp_files/menu_1.bmp");
	gwMenu_2 = SDL_LoadBMP("bmp_files/menu_2.bmp");
	gwMenu_3 = SDL_LoadBMP("bmp_files/menu_3.bmp");

	// apply the first menu bg to game window
	SDL_BlitSurface(gwMenu_1, NULL, gwSurface, NULL);
	SDL_UpdateWindowSurface(gameWindow);

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
		switch (cur_menu_ind) {
		case 1:
			SDL_BlitSurface(gwMenu_2, NULL, gwSurface, NULL);
			cur_menu_ind++;
			break;
		case 2:
			SDL_BlitSurface(gwMenu_3, NULL, gwSurface, NULL);
			cur_menu_ind++;
			break;
		case 3:
			SDL_BlitSurface(gwMenu_1, NULL, gwSurface, NULL);
			cur_menu_ind = 1;
			break;
		}
		SDL_UpdateWindowSurface(gameWindow);
		SDL_Delay(200);
	}
}

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
	SDL_Rect fillRect = {
		WIND_WIDTH / 2,
		WIND_HEIGHT / 2,
		EM_WIDTH,
		EM_HEIGHT };

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

void closeGameWindow()
{
	// release menu surface variable
	// * window surface handles by destroy window
	SDL_FreeSurface(gwMenu_1);
	gwMenu_1 = NULL;	
	SDL_FreeSurface(gwMenu_2);
	gwMenu_2 = NULL;
	SDL_FreeSurface(gwMenu_3);
	gwMenu_3 = NULL;

	// release the window variable
	SDL_DestroyWindow(gameWindow);
	gameWindow = NULL;

	// close all SDL processes
	SDL_Quit();
}

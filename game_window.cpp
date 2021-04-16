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
SDL_Renderer* gwRenderer   = NULL;	// 
SDL_Texture* emBgTex = NULL;
SDL_Surface* gwSurface = NULL;
SDL_Surface* gwMenu_1  = NULL;
SDL_Surface* gwMenu_2  = NULL;
SDL_Surface* gwMenu_3  = NULL;
SDL_Surface* siBezel   = NULL;

// function prototypes
bool initGameWindow();	// initializes the game window
void loadMainMenu();	// load the main menu files
void waitForMenuEvent();// wait for the user to make a selection 
void runEmulator();		// run the emulator
void closeGameWindow();	// shut down procedure for the game

int main(int argc, char* argv[])
{
	initGameWindow();
	loadMainMenu();
	waitForMenuEvent();
	// close the window
	closeGameWindow();

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
	// load the menu BG files
	gwMenu_1 = SDL_LoadBMP("bmp_files/menu_1.bmp");
	gwMenu_2 = SDL_LoadBMP("bmp_files/menu_2.bmp");
	gwMenu_3 = SDL_LoadBMP("bmp_files/menu_3.bmp");
	
	// apply the first menu bg to game window
	SDL_BlitSurface(gwMenu_1, NULL, gwSurface, NULL);
	// update the surface of the main window
	SDL_UpdateWindowSurface(gameWindow);

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
					runEmulator();
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

void runEmulator()
{
	// flag to signal program exit
	bool quit_flag = false;

	// event to handle 
	SDL_Event evnt;

	// load the emulator bezel to the screen
	siBezel = SDL_LoadBMP("bmp_files/space_invaders_bezel.bmp");
	//SDL_BlitSurface(siBezel, NULL, gwSurface, NULL);

	// load the emulator container
	// START TEST CODE FOR EMULATOR WINDOW *************************
	emBgTex = SDL_CreateTextureFromSurface(gwRenderer, siBezel);
	/*SDL_SetRenderTarget(gwRenderer, emBgTex);
	SDL_Rect fillRect = { 
		EM_WIDTH, 
		EM_HEIGHT, 
		WIND_WIDTH / 4, 
		WIND_HEIGHT / 4 };
	SDL_RenderClear(gwRenderer);
	SDL_SetRenderDrawColor(gwRenderer, 0xFF, 0x00, 0x00, 0xFF);
	SDL_RenderFillRect(gwRenderer, &fillRect);*/
	SDL_RenderCopy(gwRenderer, emBgTex, NULL, NULL);
	SDL_RenderPresent(gwRenderer);
	// END TEST CODE FOR EMULATOR WINDOW *************************

	SDL_UpdateWindowSurface(gameWindow);

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
	}
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

	// release the space invader bezel
	SDL_FreeSurface(siBezel);
	siBezel = NULL;

	// release the window variable
	SDL_DestroyWindow(gameWindow);
	gameWindow = NULL;

	// close all SDL processes
	SDL_Quit();
}

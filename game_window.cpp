#pragma once
#include "SDL.h"
#include <stdio.h>
#include <string>

// window dimensions
const int WIND_WIDTH  = 356;
const int WIND_HEIGHT = 324;

// global SDL variables
SDL_Window* gameWindow = NULL;
SDL_Surface* gwSurface = NULL;
SDL_Surface* gwMenu_1  = NULL;
SDL_Surface* gwMenu_2  = NULL;
SDL_Surface* gwMenu_3  = NULL;

// function prototypes
bool initGameWindow();	// initializes the game window
bool loadMainMenu();	// load the main menu of the game
void waitForMenuEvent();// wait for the user to make a selection 
void runEmulator();		// run the emulator
void closeGameWindow();	// shut down procedure for the game
SDL_Surface* loadSurfaceFile(std::string fPath);	// creates surface from passed file

int main(int argc, char* argv[])
{
	initGameWindow();
	loadMainMenu();

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
	}
	return load_success;
}

bool loadMainMenu()
{
	bool load_success = true;
	//Load splash image
	gwMenu_1 = SDL_LoadBMP("bmp_files/menu_1.bmp");
	if (gwMenu_1 == NULL)
	{
		printf("Error loadMainMenu [background] Error Message: %s\n", SDL_GetError());
		load_success = false;
	}
	else {
		// apply menu bg to game window
		SDL_BlitSurface(gwMenu_1, NULL, gwSurface, NULL);
		// update the surface of the main window
		SDL_UpdateWindowSurface(gameWindow);
		// open window with a delay
		SDL_Delay(7000);
	}
	return load_success;
}

void closeGameWindow()
{
	// release menu surface variable
	// * window surface handles by destroy window
	SDL_FreeSurface(gwMenu_1);
	gwMenu_1 = NULL;

	// release the window variable
	SDL_DestroyWindow(gameWindow);
	gameWindow = NULL;

	// close all SDL processes
	SDL_Quit();
}

SDL_Surface* loadSurfaceFile(std::string fPath)
{
	//Load image at specified path
	SDL_Surface* loadedSurface = SDL_LoadBMP(fPath.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL Error: %s\n", fPath.c_str(), SDL_GetError());
	}

	return loadedSurface;
}

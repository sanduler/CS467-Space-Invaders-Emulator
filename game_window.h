//#pragma once

#include <SDL.h>
#include <stdio.h>
#include <string>
#include <math.h> 

// **** CODE BELOW USED TO FIND WINDOW DIMENSIONS ****
// window dimensions 
// based on the SI bezel (387 : 400)
//const double BEZEL_RATIO = 1.4;

// warnings turned off becuase rounding is OK here
//#pragma warning(disable:4244)
//const int WIND_WIDTH = 387 * BEZEL_RATIO;
//const int WIND_HEIGHT = 400 * BEZEL_RATIO;
//#pragma warning(default:4244)
// ***************************************************

// Computation results from code ^
const int WIND_WIDTH	= 541;
const int WIND_HEIGHT	= 560;

// emulator window dimensions
// based on the SI ROM (7 : 8)
const int EM_WIDTH		= 224;
const int EM_HEIGHT		= 256;

// joystick variables
SDL_Joystick* gameController = NULL;

// global SDL variables
SDL_Window* gameWindow = NULL;			// main window for game
SDL_Renderer* gwRenderer = NULL;		// main renderer
SDL_Texture* siContainer;
SDL_Texture* siBackground;

// function prototypes
bool initGameWindow();					// initializes the game window
void initJoySticks();					// look for and initialize joysticks
void waitForMenuEvent();				// wait for the user to make a selection 
void menuAnimation(bool destroy_flag);	// handle the main menu animation
void runSpaceInvaders();				// run the emulator for space invaders
void closeGameWindow();					// shut down procedure for the game
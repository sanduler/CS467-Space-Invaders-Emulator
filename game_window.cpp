#include "game_window.h"
#include "SI_GameLoop.h"

i8080_CPU i8080;

int main(int argc, char* argv[])
{
	initGameWindow();					// initialize the SDL structures
	initJoySticks();
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
	if (SDL_Init(SDL_INIT_EVERYTHING | SDL_INIT_JOYSTICK | SDL_INIT_TIMER) < 0) {
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
		//gwRenderer = SDL_CreateRenderer(gameWindow, -1, SDL_RENDERER_ACCELERATED);
		gwRenderer = SDL_CreateRenderer(gameWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		// check for successful creation of the renderer
		if (gwRenderer == NULL) {
			printf("Error initGameWindow [renderer] Error Message: %s\n", SDL_GetError());
			load_success = false;
		}
	}
	return load_success;
}

/*
	Check if any joysticks are connected and if they are set them up
*/
void initJoySticks()
{
	// joysticks already inititiated in initGameWindow() so just need
	// to check if they exist here
	if (SDL_NumJoysticks() < 1) {
		printf("No Joysticks connected \n");
	}
	else {
		gameController = SDL_JoystickOpen(0);
		if (gameController == NULL) {
			printf("ERROR: Unable to load joystick");
		}
		else {
			printf("Joystick connected\n");
		}
	}
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
			switch (getUserInput(evnt)) {
			case SI_INPUT::QUIT:
				printf("QUIT\n");
				quit_flag = true;
				break;
			case SI_INPUT::INSERT_COIN:
				printf("COIN INSERTED\n");
				runSpaceInvaders();
				break;
			default: break;
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
	// load the emulator bezel as a texture
	SDL_Surface* siBezel = SDL_LoadBMP("bmp_files/space_invaders_bezel.bmp");
	siBackground = SDL_CreateTextureFromSurface(gwRenderer, siBezel);	

	// create a texture to run the emulator inside of 
	siContainer = SDL_CreateTexture(
		gwRenderer,
		SDL_PIXELFORMAT_RGBA8888,
		SDL_TEXTUREACCESS_STREAMING,
		EM_WIDTH,					//28 * EM_WIDTH,
		EM_HEIGHT);

	// Load the ROM
	i8080.state.LoadRomFiles();



	// start the space invaders game loop
	SI_GameLoop();
	//SI_GameLoop(siBackground);

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

	// close the joystick
	SDL_JoystickClose(gameController);
	gameController = NULL;

	// destroy the renderer
	SDL_DestroyRenderer(gwRenderer);
	gwRenderer = NULL;

	// close all SDL processes
	SDL_Quit();
}

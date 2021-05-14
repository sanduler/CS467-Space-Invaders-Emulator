// Header File for SI_GameLoop



//#include <SDL2/begin_code.h>
#include <SDL.h>
#include "OpCodeFunctions.h"
#include "i8080_struct.h"

const int JOYSTICK_DEAD_ZONE = 8000;

// Enum to generalize the action from an event 
// Allows for a single evaluation of keyboard/joystick
//#pragma once
enum class SI_INPUT {
	MOVE_LEFT,
	MOVE_RIGHT,
	FIRE,
	QUIT,
	INSERT_COIN,
	NO_ACTION
};

void SI_GameLoop(SDL_Texture* siContainer);
SI_INPUT getUserInput(SDL_Event &evnt);
void SI_handleUserInput(bool &quit_flag);
void SI_handleExecuteOpCode();
void SI_handleScreenUpdate(SDL_Texture* siContainer);
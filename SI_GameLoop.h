#pragma once
#include "SDL.h"
#include "Opcodes/OpCodeFunctions.h"
#include "i8080_struct.h"

const int JOYSTICK_DEAD_ZONE = 8000;

// Enum to generalize the action from an event 
// Allows for a single evaluation of keyboard/joystick
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
void SI_handleScreenUpdate(SDL_Texture* siContainer);
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
	P1_MOVE_LEFT,
	P1_MOVE_RIGHT,
	P1_FIRE,
	QUIT,
	INSERT_COIN,
	P2_MOVE_LEFT,
	P2_MOVE_RIGHT,
	P2_FIRE,
	P1_START,
	P2_START,
	TILT,
	NO_ACTION
};

void SI_GameLoop();
SI_INPUT getUserInput(SDL_Event &evnt);
void SI_handleUserInput(bool &quit_flag);
void SI_handleExecuteOpCode();
void SI_handleScreenUpdate();

void SI_ResetInputs();

void SI_16BitShiftRegister();
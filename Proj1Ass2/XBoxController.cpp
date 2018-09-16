// Ass1.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include "XBoxController.h"
#include <cstdlib>
#include <iostream>

#define PRESSED 1
#define NPRESSED 0
#define MAX_THUMB 32767

//functions for XBoxController class

//Constructor for XBoxController class
GamePad::XBoxController::XBoxController(XInputWrapper* xinput, DWORD id) {
	//creates a new XINPUT_STATE pointer 
	this->pState = new XINPUT_STATE;

	//sets the variables to be the what is passed into the constructor
	this->xInput = xinput;
	this->id = id;

	//sets the starting deadzone radius to be 0
	this->deadzone = 0;

}

//Gets the unique controllerID
DWORD GamePad::XBoxController::GetControllerId() {
	return id;
}

//Checks the controller is connected through use of XInputGetState function which returns true when connected
bool GamePad::XBoxController::IsConnected() {
	return xInput->XInputGetState(id, pState);
}

/*
*Functions for buttons being pressed, #defines have been added
*for functions that return bools, with PRESSED = 1 and NPRESSED = 0
*/

bool GamePad::XBoxController::PressedA() {
	//Update pstate
	DWORD err = xInput->XInputGetState(id, pState);
	//Check if button is pressed through bitmask
	if (!err && pState->Gamepad.wButtons & XINPUT_GAMEPAD_A) {
		return PRESSED;
	}
	else {
		return NPRESSED;
	}
}

bool GamePad::XBoxController::PressedB() {
	//Update pstate
	DWORD err = xInput->XInputGetState(id, pState);
	//Check if button is pressed through bitmask
	if (!err && pState->Gamepad.wButtons & XINPUT_GAMEPAD_B) {
		return PRESSED;
	}
	else {
		return NPRESSED;
	}
}

bool GamePad::XBoxController::PressedX() {
	//Update pstate
	DWORD err = xInput->XInputGetState(id, pState);
	//Check if button is pressed through bitmask
	if (!err && pState->Gamepad.wButtons & XINPUT_GAMEPAD_X) {
		return PRESSED;
	}
	else {
		return NPRESSED;
	}

}

bool GamePad::XBoxController::PressedY() {
	//Update pstate
	DWORD err = xInput->XInputGetState(id, pState);
	//Check if button is pressed through bitmask
	if (!err && pState->Gamepad.wButtons & XINPUT_GAMEPAD_Y) {
		return PRESSED;
	}
	else {
		return NPRESSED;
	}
}


bool GamePad::XBoxController::PressedLeftShoulder() {
	//Update pstate
	DWORD err = xInput->XInputGetState(id, pState);
	//Check if button is pressed through bitmask
	if (!err && pState->Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_SHOULDER) {
		return PRESSED;
	}
	else {
		return NPRESSED;
	}
}

bool GamePad::XBoxController::PressedRightShoulder() {
	//Update pstate
	DWORD err = xInput->XInputGetState(id, pState);
	//Check if button is pressed through bitmask
	if (!err && pState->Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_SHOULDER) {
		return PRESSED;
	}
	else {
		return NPRESSED;
	}
}

bool GamePad::XBoxController::PressedLeftDpad() {
	//Update pstate
	DWORD err = xInput->XInputGetState(id, pState);
	//Check if button is pressed through bitmask
	if (!err && pState->Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_LEFT) {
		return PRESSED;
	}
	else {
		return NPRESSED;
	}
}

bool GamePad::XBoxController::PressedRightDpad() {
	//Update pstate
	DWORD err = xInput->XInputGetState(id, pState);
	//Check if button is pressed through bitmask
	if (!err && pState->Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_RIGHT) {
		return PRESSED;
	}
	else {
		return NPRESSED;
	}

}

bool GamePad::XBoxController::PressedUpDpad() {
	//Update pstate
	DWORD err = xInput->XInputGetState(id, pState);
	//Check if button is pressed through bitmask
	if (!err && pState->Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_UP) {
		return PRESSED;
	}
	else {
		return NPRESSED;
	}

}

bool GamePad::XBoxController::PressedDownDpad() {
	//Update pstate
	DWORD err = xInput->XInputGetState(id, pState);
	//Check if button is pressed through bitmask
	if (!err && pState->Gamepad.wButtons & XINPUT_GAMEPAD_DPAD_DOWN) {
		return PRESSED;
	}
	else {
		return NPRESSED;
	}
}

bool GamePad::XBoxController::PressedStart() {
	//Update pstate
	DWORD err = xInput->XInputGetState(id, pState);
	//Check if button is pressed through bitmask
	if (!err && pState->Gamepad.wButtons & XINPUT_GAMEPAD_START) {
		return PRESSED;
	}
	else {
		return NPRESSED;
	}
}

bool GamePad::XBoxController::PressedBack() {
	//Update pstate
	DWORD err = xInput->XInputGetState(id, pState);
	//Check if button is pressed through bitmask
	if (!err && pState->Gamepad.wButtons & XINPUT_GAMEPAD_BACK) {
		return PRESSED;
	}
	else {
		return NPRESSED;
	}

}

bool GamePad::XBoxController::PressedLeftThumb() {
	//Update pstate
	DWORD err = xInput->XInputGetState(id, pState);
	//Check if button is pressed through bitmask
	if (!err && pState->Gamepad.wButtons & XINPUT_GAMEPAD_LEFT_THUMB) {
		return PRESSED;
	}
	else {
		return NPRESSED;
	}

}

bool GamePad::XBoxController::PressedRightThumb() {
	//Update pstate
	DWORD err = xInput->XInputGetState(id, pState);
	//Check if button is pressed through bitmask
	if (!err && pState->Gamepad.wButtons & XINPUT_GAMEPAD_RIGHT_THUMB) {
		return PRESSED;
	}
	else {
		return NPRESSED;
	}

}

BYTE GamePad::XBoxController::LeftTriggerLocation() {
	//Update pstate
	DWORD err = xInput->XInputGetState(id, pState);
	return pState->Gamepad.bLeftTrigger;

}

BYTE GamePad::XBoxController::RightTriggerLocation() {
	//Update pstate
	DWORD err = xInput->XInputGetState(id, pState);
	return pState->Gamepad.bRightTrigger;

}

/*
* The function scales the x and y location of the left thumb
* by calculating the relative scale (a percentage) which
* the x and y have moved independently outside the deadzone
* and then applies this scale to the range of MAX_THUMB
*/
GamePad::Coordinate GamePad::XBoxController::LeftThumbLocation() {
	//Update pstate
	DWORD err = xInput->XInputGetState(id, pState);
	//Obtain the current x and y location of the left thumb
	float lx = pState->Gamepad.sThumbLX;
	float ly = pState->Gamepad.sThumbLY;

	//variables that will hold the normalised values taking deadzone into account
	float scaledlx = 0;
	float scaledly = 0;

	//get the current radius, Pythagoras Theorem
	float currRadius = sqrt(lx*lx + ly * ly);
	//clip radius
	if (currRadius > MAX_THUMB) {
		currRadius = MAX_THUMB;
	}
	//normalise x and y coordinates
	if (currRadius > deadzone) {
		float scale = (currRadius - deadzone) / (MAX_THUMB - deadzone);
		float theta = atan2(ly, lx);
		scaledlx = MAX_THUMB * cos(theta) * scale;
		scaledly = MAX_THUMB * sin(theta) * scale;
	}

	//create the scaled variable to be returned
	Coordinate lThumbLocation = Coordinate::Coordinate((SHORT)scaledlx, (SHORT)scaledly);
	return lThumbLocation;
}

/*
*The function scales the x and y location of the right thumb
* by calculating the relative scale(a percentage) which
* the x and y have moved independently outside the deadzone
* and then applies this scale to the range of MAX_THUMB
*/
GamePad::Coordinate GamePad::XBoxController::RightThumbLocation() {

	//Update pstate
	DWORD err = xInput->XInputGetState(id, pState);
	//Obtain the current x and y location of the left thumb
	float rx = pState->Gamepad.sThumbRX;
	float ry = pState->Gamepad.sThumbRY;

	//variables that will hold the normalised values taking deadzone into account
	float scaledrx = 0;
	float scaledry = 0;

	//get the current radius, Pythagoras Theorem
	float currRadius = sqrt(rx*rx + ry * ry);
	//clip radius
	if (currRadius > MAX_THUMB) {
		currRadius = MAX_THUMB;
	}
	//normalise x and y coordinates
	if (currRadius > deadzone) {
		float scale = (currRadius - deadzone) / (MAX_THUMB - deadzone);
		float theta = atan2(ry, rx);
		scaledrx = MAX_THUMB * cos(theta) * scale;
		scaledry = MAX_THUMB * sin(theta) * scale;
	}
	//create the scaled variable to be returned
	Coordinate rThumbLocation = Coordinate::Coordinate((SHORT)scaledrx, (SHORT)scaledry);
	return rThumbLocation;
}

//Sets the value of vibration of left and right motors based on inputs
void GamePad::XBoxController::Vibrate(WORD left, WORD right) {
	//create point to the struct
	XINPUT_VIBRATION *pVibration = new XINPUT_VIBRATION;
	//sets values to established inputs
	pVibration->wLeftMotorSpeed = left;
	pVibration->wRightMotorSpeed = right;
	//actually sets the state
	xInput->XInputSetState(id, pVibration);

}

//sets the deadzone radius to input value, affects thumblocation functions
void GamePad::XBoxController::SetDeadzone(unsigned int radius) {
	deadzone = radius;
}



#include "InputSource.h"
#include "raylib.h"

void InputSource::update()
{
    if (gamepadIsUsed()) device = InputSourceDevice::GAMEPAD;
    if (keyboardIsUsed()) device = InputSourceDevice::KEYBOARD;
}

bool InputSource::gamepadIsUsed()
{
    int button = GetGamepadButtonPressed();
    return button != GAMEPAD_BUTTON_UNKNOWN;
}

bool InputSource::keyboardIsUsed()
{
    int key = GetKeyPressed();
    return key != 0;
}

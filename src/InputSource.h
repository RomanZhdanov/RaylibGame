#pragma once

enum class InputSourceDevice {
    KEYBOARD,
    GAMEPAD
};

class InputSource
{
    public:
        void update();
        int getGamepad() { return gamepad; }
        bool gamepadIsActive() { return device == InputSourceDevice::GAMEPAD; }
        bool keyboardIsActive() { return device == InputSourceDevice::KEYBOARD; }
        bool gamepadIsUsed();
        bool keyboardIsUsed();
    private:
        int gamepad{};
        InputSourceDevice device{ InputSourceDevice::KEYBOARD };
};

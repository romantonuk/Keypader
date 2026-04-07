# DOCUMENTATION

## struct ISoftDriver_keypad
DESCRIPTION : Simple driver interface for using button matrices.
###### PLACEMENT : Inside keypader namespace.

## uint8_t isPressed(driver, coulumn, row)
DESCRIPTION : Function to to check button state of the button.
PLACEMENT : Inside keypader namespace.
USAGE : uint8_t buttonState = isPressed(my_driver, 0, 0);

## struct DirectPinsSoft_keypad
DESCRIPTION : Driver for button matrices used for communicating using direct pins connections (without anything in-betwen like shift register).
PLACEMENT : Inside DefaultSoftDrivers_keypad namespace.


### Check this [example] for detailed usage.

[example]: https://github.com/romantonuk/Keypader/blob/main/examples/CheckFor1stButton/checkFor1stButton.ino

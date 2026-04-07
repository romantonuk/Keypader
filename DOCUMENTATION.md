# DOCUMENTATION

## struct ISoftDriver_keypad /n
DESCRIPTION : Simple driver interface for using button matrices. /n
PLACEMENT : Inside keypader namespace. /n

## uint8_t isPressed(driver, coulumn, row) /n
DESCRIPTION : Function to to check button state of the button. /n
PLACEMENT : Inside keypader namespace. /n
USAGE : uint8_t buttonState = isPressed(my_driver, 0, 0); /n

## struct DirectPinsSoft_keypad /n
DESCRIPTION : Driver for button matrices used for communicating using direct pins connections (without anything in-betwen like shift register). /n
PLACEMENT : Inside DefaultSoftDrivers_keypad namespace. /n


### Check this [example] for detailed usage. /n

[example]: https://github.com/romantonuk/Keypader/blob/main/examples/CheckFor1stButton/checkFor1stButton.ino

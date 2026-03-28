# Module Breakdown

## Core Modules Observed

- `User/main.c`: main loop and high-level action dispatch
- `HardWare/BlueTooth.*`: command reception for Bluetooth and voice serial channels
- `HardWare/PetAction.*`: servo movement routines
- `HardWare/Face_Config.*`: OLED face rendering and expression switching
- `HardWare/PWM.*`: LED and servo-related PWM behavior

## Interaction Pattern

The base project uses a state-driven flow:

1. receive command from a serial source
2. translate the command into an action mode or face mode
3. execute a motion or expression routine
4. keep auxiliary feedback such as LED state in sync

## Representative Behaviors

The analyzed action modes cover a surprisingly complete pet behavior set, including:

- sit and stand
- crawl or get down
- forward and backward motion
- left and right rotation
- swing and tail swing
- jump forward and backward
- hello or waving action
- stretch behaviors

## Engineering Value

This structure is a good foundation for embedded interaction design because it already separates:

- input reception
- action selection
- physical behavior
- visual feedback

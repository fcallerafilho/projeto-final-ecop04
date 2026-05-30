# Airport Flight Information Display

Embedded systems project implementing a real-time flight 
information board on a PIC18F4520 microcontroller.

## Overview

Simulates an airport departure board using the PIC18F4520's 
onboard peripherals. The system manages flight state transitions, 
drives multiple output devices simultaneously, and responds to 
user input — written entirely in C with no OS or HAL abstraction.

## Hardware

- **MCU:** Microchip PIC18F4520
- **Outputs:** 16x2 LCD display, 7-segment display, LED array
- **Inputs:** Push buttons for flight info navigation
- **Toolchain:** MPLAB X, XC8 compiler

## Features

- Finite state machine managing flight lifecycle:
  `BOARDING → DEPARTING → STANDBY → IDLE`
- Boarding countdown timer on 7-segment display
- LED alerts synchronized with boarding state
- Button-driven navigation across flight metadata
  (status, destination, duration, aircraft type)
- Bare-metal peripheral drivers for LCD, 7-segment,
  and GPIO written in C

## Implementation Notes

Peripheral drivers developed in C directly against the 
PIC18F4520 datasheet. The project focuses on state machine 
design and coordinated multi-peripheral output on 
constrained hardware with no dynamic memory allocation.

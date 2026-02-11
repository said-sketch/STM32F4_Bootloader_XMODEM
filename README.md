# STM32F4_Bootloader_XMODEM

This project implements a bootloader for STM32F4 microcontrollers with the following features:

- UART-based communication for debug and firmware update
- XMODEM protocol for flashing application binaries over UART
- Flash memory erase, write, and read management
- Jump to user application with stack pointer and vector table validation
- Optional debugging messages and scalable configuration

## Bootloader Memory Layout

- Bootloader occupies `0x08000000` to `0x0801FFFF`
- Application flash starts at `0x08020000`
- Configurable application size and flash sectors

## Usage

1. Flash the bootloader using ST-Link or STM32CubeProgrammer.
2. Send the application `.bin` via UART using Tera Term or similar.
3. Press 'J' in the bootloader menu to jump to the application.

## Notes

- Ensure the application `.bin` includes the proper vector table at the start.
- UART debugging messages can be enabled via `BL_config.h`.
- The bootloader prevents jumping to invalid applications unless explicitly skipped.


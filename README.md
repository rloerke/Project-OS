# Operating Systems Project
## Written by Ray Loerke

This project is part of the CS 456: Operating Systems Course taught by Professor Brian Law.

The purpose of this project is to create a rudimentary operating system that can read, run, copy, and delete files.

## File Descriptions
* kernel.c -The operating system's kernel
* compileOS.bash -A shell script used to create a final bootable floppy disk image
* uprog1.c -An example user program that displays a message and then terminates
* uprog2.c -A different example user program that displays a message and then temrinates
* shell.c -The source code for the command line shell
* userlib.c/userlib.h -Declaration of command line shell library functions

## Command Line Shell Description
The following are the available shell commands:
* type <file> -Displays the contents of <file> on the screen
* execute <file> -Loads <file> into memory and executes it
* d <file> -Removes <file> from the disk
* copy <src> <dest> -Makes a copy of the file <src> as a new file <dest>
* dir -Displays a list of files currently stored on the disk

## Tools
This project will use:
* bochs and bochs-X -An x86 processor emulator with X GUI
* bcc (Bruce Evan's C Compiler) -A 16-bit C compiler
* as86 and id86 -A 16-bit 0x86 assembler and linker
* gcc/g++ -The standard 32-bit GNU C compiler
* nasm -The Netwide Assembler
* hexedit/hexdump -Utilities that allow you to edit/view a file in hexadecimal byte-by-byte
* dd -A standard low-level copying utility

## Files
These files were provided for this project:
* bootload.asm -Assembly code for the boot loader
* kernel.asm -Assembly language routines to be used in the kernel
* opsys.bxrc -bochs configuration file
* test.img -Bootable 1.44MB floppy image for testing bochs
* message.txt -A small text file used to test the read sector system call
* dir.img -A Disk Directory containing the kernel
* lib.asm -Assembly language routine for invoking from user programs interrupts
* loadfile.c -A utility program that will copy files to the floppy disk image and update the Disk Directory and Disk Map appropriately. 
* map.img -A Disk Map with the kernel sectors marked as used

## Acknowledgement
This project was designed (with minor adaptation by Brian Law) by Michael Black at American University.
His paper is titled "Build an operating system from scratch: a project for an introductory operating systems course".

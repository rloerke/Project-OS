#!/bin/bash
#Ray Loerke, Compile-Assemble-Link script

#To reset the disk to all 0's
dd if=/dev/zero of=floppya.img bs=512 count=2880
#To load the bootloader into sector 0
dd if=bootload of=floppya.img bs=512 count=1 conv=notrunc seek=0

#First we compile the kernel
bcc -ansi -c -o kernel.o kernel.c
#Then we assemble the kernel.asm file
as86 kernel.asm -o kernel_asm.o
#Next link the kernel.o and kernel_asm.o files
ld86 -o kernel -d kernel.o kernel_asm.o
#We copy the disk map into the disk image at sector 1
dd if=map.img of=floppya.img bs=512 count=1 seek=1 conv=notrunc
#Copy the disk directory into sector 2
dd if=dir.img of=floppya.img bs=512 count=1 seek=2 conv=notrunc
#Then we copy the kernel into sector 3
dd if=kernel of=floppya.img bs=512 conv=notrunc seek=3 

#Compile loadFile.c
gcc -o loadFile loadFile.c
#Copy message.txt to the disk image
./loadFile message.txt

#Compile shell.c
bcc -ansi -c -o shell.o shell.c
#Compile userlib.c
bcc -ansi -c -o userlib.o userlib.c
#Then assemble the lib.asm file
as86 lib.asm -o lib.o
#Link shell, userlib, and lib
ld86 -o shell -d shell.o userlib.o lib.o
#Load shell onto the disk
./loadFile shell

#Compile uprog1
bcc -ansi -c -o uprog1.o uprog1.c
#Link uprog1 to lib
ld86 -o uprog1 -d uprog1.o lib.o
#And load the file onto the disk
./loadFile uprog1

#Compile uprog2
bcc -ansi -c -o uprog2.o uprog2.c
#Link uprog1 to lib
ld86 -o uprog2 -d uprog2.o lib.o
#And load the file onto the disk
./loadFile uprog2

#Finaly, we run bochs
bochs -f opsys.bxrc -q

#To run this script: ./compileOS.bash
#To link the shared folder: sudo mount -t vboxsf C_DRIVE ~/share/

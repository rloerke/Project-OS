// Ray Loerke
// userlib is a library of wrappers for interrupt calls to be used when writing programs


// printS displays a string on the screen
// It takes a pointer to a char array where the desired string is stored
// Returns the number of characters printed
// Corresponds to interrupt 0x21- 0x00
int printS(char *addr) {
	return interrupt(0x21, 0, addr, 0, 0);
}


// readC takes in a char from user and stores it in a buffer
// It takes in a pointer to a buffer where the input will be stored
// Returns 1 if successful
// Corresponds to interrupt 0x21- 0x11
int readC(char *buf) {
	return interrupt(0x21, 0x11, buf, 0, 0);
}


// readS takes in a line of text from the user and stores it in a buffer
// It takes a pointer to a char array where the input will be sotred,
// and an int indicating the maximum capacity of that buffer array
// Returns the number of characters placed into the buffer 
// Corresponds to interrupt 0x21- 0x01
int readS(char *buf, int capacity) {
	return interrupt(0x21, 0x01, buf, capacity, 0);
}


// readF reads a file from a floppy disk and stores the contents of that file in a buffer
// It takes a pointer to a char array containing the name of the file to be read,
// a pointer to a char array where the contents of the file will be placed,
// and an int indicating the maximum capacity of the buffer
// Returns the number of sectors that were read, returns -1 if unsuccessful
// Corresponds to interrupt 0x21- 0x03
int readF(char *name, char *buf, int capacity) {
	return interrupt(0x21, 0x03, name, buf, capacity);
}


// exec executes a program from a floppy disk
// It takes a pointer to a char array containing the name of the program,
// and an integer indicating the segment of memory the file should be loaded into
// Returns -1 if the program was not found, -2 if the segment is invalid, and -3 if the file is not an executable
// Returns nothing if successful
// Corresponds to interrupt 0x21- 0x04
int exec(char *name, int seg) {
	return interrupt(0x21, 0x04, name, seg, 0);
}


// term terminates a function and executes the shell
// It does not take any inputs or return anything
// Corresponds to interrupt 0x21- 0x05
void term() {
	interrupt(0x21, 0x05, 0, 0, 0);
}


// deleteF removes a file from the disk
// It takes a pointer to a char array containing the name of the file
// Returns 1 if successful or -1 if the file can't be found
// Corresponds to interrupt 0x21- 0x07
int deleteF(char *name) {
	return interrupt(0x21, 0x07, name, 0, 0);
}


// writeF copies data from a buffer onto the disk
// It takes a pointer to a char array containing the name of the file,
// a pointer to a char array where the contents of the file can be found,
// and the size of the file in number of sectors
// Returns the number of sectors written if successful,
// -1 if there is no disk directory entry available, 
// and -2 if there are not enough free sectors to hold the file
// Corresponds to interrupt 0x21- 0x05
int writeF(char *name, char *buf, int numSectors) {
	return interrupt(0x21, 0x08, name, buf, numSectors);
}


// direc displays a list of files currently on the disk and their sizes
// It takes a pointer to a char array where the names of each file will be stored.
// Each name is seperated by a space.
// And a pointer to a int array where the size of each file will be stored.
// Size is the amount of sectors the file takes up.
// Corresponds to interrupt 0x21- 0x20
void direc(char *nameBuf, int *sizeBuf) {
	interrupt(0x21, 0x20, nameBuf, sizeBuf, 0);
}


// printI displays an integer on the screen
// It takes the integer to be displayed
// Returns 1 if successful
// Corresponds to interrupt 0x21- 0x21
int printI(int x) {
	return interrupt(0x21, 0x21, x, 0, 0);
}

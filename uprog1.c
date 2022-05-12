//Ray Loerke
// This is a simple program that displays a message and then terminates

void main() {
	interrupt(0x21,0,"\r\nWooHoo! I'm a user program!\r\n",0,0);
	interrupt(0x21, 0x05, 0, 0, 0);
}

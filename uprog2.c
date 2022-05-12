//Ray Loerke
// This is another simple program that displays a message and then terminates

void main() {
	interrupt(0x21,0,"\n\rSomething different!\r\n",0,0);
	interrupt(0x21, 0x05, 0, 0, 0);
}

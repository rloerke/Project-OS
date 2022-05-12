int addMagic(char* name);
int readFileX(char *filename, char *buf, int capacity, int *sec);
int readFileHelperX(int directoryNum, char *buf, char *diskDir, int capacity, int*sec);
int writeSector(char *buf, int absSector);


int addMagic(char* name){
	int i, j;
	char buf[13312];
	int sectors[26];

	buf[0] = 0x52;
	buf[1] = 0x4C;
	j = 0;

	i = readFileX(name, (buf + 2), 13310, sectors);

	if (i == -1) return -1;

	while ((sectors[j] != 0) && (j < 26)) {
		writeSector(buf + (j * 512), sectors[j]);
		j++;
	}
	return 1;
}


int readFileX(char *filename, char *buf, int capacity, int *sec) {
	int i, j, k, count, secsRead;
	char sec2[512];
	i = 0;
	j = 0;
	count = 0;
	readSector(sec2, 2);
	
	for (i; i < 512; i++) {
		if (sec2[i] == filename[0]) {
			k = i;
			for (j; j < 6; j++) {
				if (sec2[k] == filename[j]) {
					k++;
					count++;
				}	
				else {
					count = 0;
					j = 0;
					break;	
				}
			}

			if (count == 6) {
				secsRead = readFileHelper(i, buf, sec2, capacity, sec);
				return secsRead;
			}
		}	
	}
	return -1;
}


int readFileHelperX(int directoryNum, char *buf, char *diskDir, int capacity, int *sec) {
	int i, numSectors;
	i = 0;
	numSectors = 0;
	
	diskDir += (6 + directoryNum);

	while ((diskDir[i] != '\0') && (numSectors < 27)) {
		sec[i] = diskDir[i];
		numSectors++;
		i++;
	}

	i = 0;
	while (numSectors > 0) {
		if ((capacity - (512 * i)) > 512) {
			readSector(buf + (i * 16), sec[i]);
			i++;
			numSectors--;
		}
		else {
			break;
		}
	}
	return i;
}


// Writes a sector to a floppy disk
// Takes a pointer to an array where the data will be stored, and absolute sector number of the disk to be written to
// Returns 1 to indicate a successful transfer 
int writeSector(char *buf, int absSector) {
	int relSector, head, track, ax, cx, dx;

	// The absolute sector is translated into relative parts
	relSector = mod(absSector, 18 ) + 1;
	head = mod(( absSector / 18 ), 2);
	track = ( absSector / 36 );
	
	// High and low bytes are combined
	ax = 0x03 * 256 + 0x01;
	cx = track * 256 + relSector;
	dx = head * 256 + 0x00;

	interrupt(0x13, ax, buf, cx, dx);
	return 1;
}


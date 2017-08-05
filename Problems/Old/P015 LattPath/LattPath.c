#include <stdio.h>

#define LAT 2

void movement(int posX, int posY, int *paths);

/*
*Create a 2D array where the values represent the borders
*of the boxes in the lattice plane, may not need the actual
*array, possibly more for visualization
*/

void main() {

	//x and y correspond to the current positions
	int x=0, y=0, paths=0;

	movement(x, y, &paths);

	printf("The number of paths is %d\n", paths);

}

/*
*Call this function recursively and each time it ends at the
*bottom right of the array, it will increment the counter,
*this will count as a success
*/

void movement(int posX, int posY, int *paths) {

	printf("Point: (%d, %d)\n", posX, posY);

	if (posX < LAT) {
		posX++;
		movement(posX, posY, paths);
	}

	if (posY < LAT) {
		posY++;
		movement(posX, posY, paths);
	}

	if ((posX == LAT-1) && (posY == LAT-1)) {
		paths++;
	}
}

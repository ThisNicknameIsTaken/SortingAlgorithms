//#include "Figure.h"   //HW 1- 2
//#include "SimpleSort.h" //HW 4
#include "Sort.h"

void main() {

	/* HW 1 - 2
	SquarePtr square = createSquare(createDot(1, 5), 6);
	printSquare(square);
	deleteSquare(square);

	ArrayPtr arr = createArray(10);
	
	addElement(arr, createSquare(createDot(1, 5), 8));
	addElement(arr, createSquare(createDot(14, 3), 5));
	addElement(arr, createSquare(createDot(4, 7), 6));
	addElement(arr, createSquare(createDot(8, 1), 2));
	
	addElementByIndex(arr, createSquare(createDot(9, 4), 11),7);
	addElementByIndex(arr, createSquare(createDot(10, 3), 8), 9);

	printArray(arr);
	saveArray(arr);

	*/ //End of HW 1 - 2

	/* HW 4
	ArrayPtr arr = createArray(10);

	addElement(arr, createSquare(createDot(1, 5), 8));
	addElement(arr, createSquare(createDot(14, 3), 5));
	addElement(arr, createSquare(createDot(4, 7), 6));
	addElement(arr, createSquare(createDot(8, 1), 9));
	addElement(arr, createSquare(createDot(1, 7), 10));
	addElement(arr, createSquare(createDot(7, 19), 2));
	addElement(arr, createSquare(createDot(3, 10), 3));
	addElement(arr, createSquare(createDot(25, 2), 3));
	addElement(arr, createSquare(createDot(12, 5), 5));
	addElement(arr, createSquare(createDot(7, 1), 27));
	
	printf("Before sorting: \n");
	printArray(arr);

	bubbleSort(arr);
	//selectionSort(arr);
	//insertionSort(arr);

	printf("\n\n\nAfter sorting: \n");
	printArray(arr);
	*/ //End of HW 4

	int arrSize = 100;
	ArrayPtr arr = autoCreateArray(arrSize);

	printf("Before sorting: \n");
	printArray(arr);

	quickSort(arr, 0, arrSize - 1);
	//shellSort(arr);

	int linearTarget = 8100;
	int binaryTarget = 8100;

	int linearSearchResult = linearSearch(arr, linearTarget);
	int binarySearchResult = binarySearch(arr, binaryTarget);

	printf("\n\n\nAfter sorting: \n");
	printArray(arr);
	
	printf("\n\n\nSearch Results:\nlinear search for %i is %i\nbinary search for %i is %i\n", linearTarget, linearSearchResult, binaryTarget, binarySearchResult);

	system("pause");
}
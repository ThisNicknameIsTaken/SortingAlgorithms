#include "Sort.h"

void shellSort(ArrayPtr arr) {
	int theInner = 0;
	int theOuter = 0;
	int theH = 1; // start h = 1

	//1. Calculate start value of h
	while (theH <= arr->length / 3)
	{
		theH = theH * 3 + 1; // 1, 4, 13, 40, 121, ....
	}

	//2. Sequental decrease h to 1
	while (theH > 0)
	{
		for (theOuter = theH; theOuter < arr->length; theOuter++)
		{
			SquarePtr theTmp = arr->squareArr[theOuter];
			theInner = theOuter;

			// the first sub-array {0, 4, 8}
			while (theInner > theH - 1 && calculateSquare(arr->squareArr[theInner - theH]) >= calculateSquare(theTmp))
			{
				arr->squareArr[theInner] = arr->squareArr[theInner - theH];
				theInner -= theH;
			}

			arr->squareArr[theInner] = theTmp;
		}

		theH = (theH - 1) / 3; //decrease h
	}
}




void quickSort(ArrayPtr arr, int aLeftIndex, int aRightIndex)
{
	if (aRightIndex - aLeftIndex <= 0)
	{
		return; // the array size equals to 1 - the array is fully sorted
	}

	int thePivot = calculateSquare(arr->squareArr[aRightIndex]);
	int thePartitionIndex = partitionIt(arr, aLeftIndex, aRightIndex, thePivot);

	//left part sorting
	quickSort(arr, aLeftIndex, thePartitionIndex - 1);

	//right part sorting
	quickSort(arr, thePartitionIndex + 1, aRightIndex);
}

int partitionIt(ArrayPtr arr, int aLeftIndex, int aRightIndex, int aPivot)
{
	int theLeft = aLeftIndex - 1;
	int theRight = aRightIndex + 1;

	while (1)
	{
		// search the bigest element
		while (theLeft < aRightIndex && calculateSquare(arr->squareArr[++theLeft]) < aPivot);

		// search the lowest element
		while (theRight > aLeftIndex && calculateSquare(arr->squareArr[--theRight]) > aPivot);

		if (theLeft >= theRight) // pointer are the same 
		{
			break;
		}
		else
		{
			//lets to swap elements
			SquarePtr theTmp = arr->squareArr[theLeft];
			arr->squareArr[theLeft] = arr->squareArr[theRight];
			arr->squareArr[theRight] = theTmp;
		}
	}

	return theLeft; // return break position
}

int linearSearch(ArrayPtr arr, int square) {
	if (NULL == arr || square <= 0) {
		return -1;
	}

	for (int i = 0; i < arr->length; i++)
	{
		if (calculateSquare(arr->squareArr[i]) == square) {
			return i;
		}
	}

	return -1;
}
int binarySearch(ArrayPtr arr, int square) {
	if (NULL == arr || square <= 0 ) {
		return -1;
	}

	int first = 0;
	int last = arr->length - 1;
	int middle = (first + last) / 2;

	while (first <= last) {
		if (calculateSquare(arr->squareArr[middle]) < square)
			first = middle + 1;
		else if (calculateSquare(arr->squareArr[middle]) == square) {
			return middle;
		}
		else {
			last = middle - 1;
		}
		middle = (first + last) / 2;
	}

	return -1;
}

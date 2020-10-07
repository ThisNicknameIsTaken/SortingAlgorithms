#include "SimpleSort.h"

ArrayPtr bubbleSort(ArrayPtr arr)
{
	for (int theOut = arr->length - 1; theOut > 1; theOut--)
	{
		for (int theIn = 0; theIn < theOut; theIn++)
		{
			if (calculateSquare(arr->squareArr[theIn]) > calculateSquare(arr->squareArr[theIn + 1]))
			{
				SquarePtr theTmp = arr->squareArr[theIn];
				arr->squareArr[theIn] = arr->squareArr[theIn + 1];
				arr->squareArr[theIn + 1] = theTmp;
			}
		}
	}
}

ArrayPtr selectionSort(ArrayPtr arr)
{
	for (int theOut = 0; theOut < arr->length - 1; theOut++)
	{
		int theMinIndex = theOut;

		for (int theIn = theOut + 1; theIn < arr->length; theIn++)
		{
			if (calculateSquare(arr->squareArr[theIn]) < calculateSquare(arr->squareArr[theMinIndex]))
			{
				theMinIndex = theIn;
			}
		}

		SquarePtr theTmp = arr->squareArr[theOut];
		arr->squareArr[theOut] = arr->squareArr[theMinIndex];
		arr->squareArr[theMinIndex] = theTmp;
	}
}

ArrayPtr insertionSort(ArrayPtr arr)
{
	for (int theOut = 1; theOut < arr->length; theOut++)
	{
		SquarePtr theTmp = arr->squareArr[theOut];
		int theIn = theOut;

		while (theIn > 0 && calculateSquare(arr->squareArr[theIn - 1]) >= calculateSquare(theTmp))
		{
			arr->squareArr[theIn] = arr->squareArr[theIn - 1];
			--theIn;
		}

		arr->squareArr[theIn] = theTmp;
	}
}
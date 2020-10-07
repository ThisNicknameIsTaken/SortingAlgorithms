#include "Figure.h"

DotPtr createDot(int x, int y) {
	DotPtr dot = (DotPtr)malloc(sizeof(Dot));

	if (NULL != dot) {
		dot->x = x;
		dot->y = y;
	}
	else {
		printf("Error allocating memory on dot\n");
	}
	
	return dot;
}
SquarePtr createSquare(DotPtr leftBottomCornerDot, int sideSize) {
	if (NULL == leftBottomCornerDot) {
		printf("Error, Dot is NULL\n");
		return NULL;
	}

	if (sideSize <= 0) {
		printf("Error, Side size can`t be lower or equal 0\n");
		return NULL;
	}

	SquarePtr square = (SquarePtr)malloc(sizeof(Square));
	
	square->leftBottomCornerDot = leftBottomCornerDot;
	square->sideSize = sideSize;

	return square;
}

void deleteDot(DotPtr dot) {
	if (NULL == dot) {
		return;
	}

	free(dot);
}

void deleteSquare(SquarePtr square) {
	if (NULL == square) {
		return;
	}

	deleteDot(square->leftBottomCornerDot);
	free(square);
}

void printDot(DotPtr dot) {
	if (NULL == dot) {
		printf("Error, reading dot\n");
		return;
	}

	printf("x = %i\ny = %i",dot->x, dot->y);
}
void printSquare(SquarePtr square) {
	if (NULL == square) {
		printf("Error, reading square\n");
		return;
	}

	printf("Left  top corner: \n x = %i;\n y = %i;\n", square->leftBottomCornerDot->x, square->leftBottomCornerDot->y + square->sideSize);
	printf("Right top corner: \n x = %i;\n y = %i;\n", square->leftBottomCornerDot->x + square->sideSize, square->leftBottomCornerDot->y + square->sideSize);
	printf("Left  bottom corner: \n x = %i;\n y = %i;\n", square->leftBottomCornerDot->x, square->leftBottomCornerDot->y);
	printf("Right bottom corner: \n x = %i;\n y = %i;\n", square->leftBottomCornerDot->x + square->sideSize, square->leftBottomCornerDot->y);
	printf("Side size: %i\n\n", square->sideSize);
	
}

int calculateSquare(SquarePtr square) {
	if (square == NULL) {
		return -1;
	}

	int squareNum = square->sideSize * square->sideSize;
	return squareNum;
}

void printSquareToFile(SquarePtr square, FILE *fp) {
	if (NULL == square || NULL == fp) {
		return;
	}

	fprintf(fp,"{\n");

	fprintf(fp, "	\"x\" : %i, \n", square->leftBottomCornerDot->x);
	fprintf(fp, "	\"y\" : %i, \n", square->leftBottomCornerDot->y);
	fprintf(fp, "	\"size\" : %i \n", square->sideSize);

	fprintf(fp, "}");

}


ArrayPtr createArray(int length) {
	if (length <= 0) {
		printf("Error, Array Length can`t be lower or equal 0\n");
		return NULL;
	}

	ArrayPtr arr = (ArrayPtr)malloc(sizeof(Array));

	if (NULL == arr) {
		printf("Error allocating memory on array\n");
		return NULL;
	}

	SquarePtr *squareArray = (SquarePtr *)malloc(sizeof(Square) * length);

	for (int i = 0; i < length; i++)
	{
		squareArray[i] = NULL;
	}

	arr->squareArr = squareArray;
	arr->length = length;
	arr->used = 0;

	return arr;
}

ArrayPtr autoCreateArray(int length) {
	if (length <= 0) {
		printf("Error, length should be more than 0\n");
		return NULL;
	}
	
	ArrayPtr arr = createArray(length);
	srand(time(NULL));

	for (int i = 0; i < length; i++)
	{
		SquarePtr square = createSquare(createDot(rand() % 101, rand() % 101), rand() % 101);
		addElement(arr, square);
	}

	return arr;
}

int addElement(ArrayPtr arr, SquarePtr square) {
	if (arr->used < arr->length) {
		arr->squareArr[arr->used] = square;
		arr->used++;
		return arr->used - 1;
	}
	return -1;
}
int addElementByIndex(ArrayPtr arr, SquarePtr square, int index) {
	if (index >= arr->length || NULL == arr || NULL == square) {
		return -1;
	}

	SquarePtr squareToDelete = arr->squareArr[index];

	if (NULL != squareToDelete) {
		deleteSquare(squareToDelete);
	}
	else {
		arr->used++;
	}

	arr->squareArr[index] = square;
	return index;	
}

void saveArray(ArrayPtr arr) {
	if (arr == NULL) {
		printf("Error, array is NULL\n");
		return;
	}

	FILE *fp = NULL;
	fopen_s(&fp, "Square.json", "w+");

	if (arr->length != 1) {
		fprintf(fp, "[\n");
	}
	for (int i = 0; i < arr->length; i++)
	{

	
		printSquareToFile(arr->squareArr[i], fp);
		if (i != arr->length - 1 && arr->squareArr[i] != NULL) {
			fprintf(fp, ",\n");
		}
		else {
			fprintf(fp, "\n");
		}
	}
	if (arr->length != 1) {
		fprintf(fp, "]");
	}
	fclose(fp);
}

void printArray(ArrayPtr arr) {
	if (NULL == arr) {
		printf("Error, array is NULL\n");
		return;
	}

	SquarePtr tempSquare;
	for (int i = 0; i < arr->length; i++)
	{
		printf("%i:\n", i);
		tempSquare = arr->squareArr[i];
		if (tempSquare != NULL) {
			printSquare(tempSquare);
		}
		else {
			printf("	Empty\n");
		}
	}
}


void deleteArray(ArrayPtr arr) {
	if (NULL == arr) {
		return;
	}

	SquarePtr tempSquare;
	for (int i = 0; i < arr->length; i++)
	{
		tempSquare = arr->squareArr[i];
		if (tempSquare != NULL) {
			deleteSquare(tempSquare);
		}
	}

	free(arr);
}
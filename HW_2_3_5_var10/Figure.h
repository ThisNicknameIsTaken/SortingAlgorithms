#include <stdio.h>
#include <time.h>
#include <stdlib.h>

typedef struct tagDot {
	int x;
	int y;
}Dot, *DotPtr;

typedef struct tagSquare {
	DotPtr leftBottomCornerDot; 
	int sideSize;
}Square, *SquarePtr;

typedef struct tagArray {
	DotPtr *squareArr;
	int length;
	int used;
}Array ,*ArrayPtr;

DotPtr createDot(int x, int y);
SquarePtr createSquare(DotPtr leftBottomCornerDot, int sideSize);

void deleteDot(DotPtr dot);
void deleteSquare(SquarePtr square);

void printDot(DotPtr dot);
void printSquare(SquarePtr square);
void printSquareToFile(SquarePtr square, FILE *fp);

int calculateSquare(SquarePtr square);

ArrayPtr createArray(int length);
ArrayPtr autoCreateArray(int length);

int addElement(ArrayPtr arr, SquarePtr square);
int addElementByIndex(ArrayPtr arr, SquarePtr square, int index);

void saveArray(ArrayPtr arr);
void printArray(ArrayPtr arr);
void deleteArray(ArrayPtr arr);

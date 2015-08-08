/*
 ============================================================================
 Name        : {TSchulenberg}TestScoreStats.c
 Author      : Tyler Schulenberg
 Version     :
 Copyright   : Your copyright notice
 Description : Program that takes test scores and gives the user the highest, lowest, and average of the scores
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void) {

	double High = 0; // highest entered number
	double Low = 100; // lowest entered number
	double Avg; // average of all numbers
	double Sum; // sum of all numbers to be divided by final count to determine average
	int Count = 0; // amount of entered numbers
	double CurrentNum = 1; // most recently entered number
	char buffer[BUFSIZ + 1]; // space for the user to type in the test numbers
	double StandardD = 0; // standard Deviation
	double SumSquares = 0; // sum of the squares of the test scores
	double holder = 0; //computers a step of the standard deviation

	printf("***** TEST SCORE STATISTICS v1.0 *****\n");
	printf(
			"Type test score into console and then press enter.\n When all scores have been inputed press enter without any input values.");
	do {
		CurrentNum = atof(gets(buffer)); // gets number from input and converts to a double
		if (CurrentNum == 0)
			break;
		if (CurrentNum >= High) // if to assign high values
			High = CurrentNum;
		if (CurrentNum <= Low) { // if to assign low values
			Low = CurrentNum;
		}
		Count = Count + 1; // adds 1 to count per rotation
		Sum = Sum + CurrentNum; // adds current number to sum
		Avg = Sum / Count; // computes average
		SumSquares = SumSquares + pow (Sum,2);
	} while (buffer[0] != '\0'); // while loop executes until user presses enter without an input

	/* equations computer Standard Deviation */
	holder = (SumSquares - (pow(Sum,2) / Count)) / Count;
	StandardD =  sqrt  (holder);

	 /* next 4 lines prints out the collected data */
	printf("The highest test score was %g.\n", High);
	printf("The lowest test score was %g.\n", Low);
	printf("The test average was %g.\n", Avg);
	printf("There were a total of %d tests.\n", Count);
	printf("The Standard deviation is %g.", StandardD);

	return EXIT_SUCCESS;
}

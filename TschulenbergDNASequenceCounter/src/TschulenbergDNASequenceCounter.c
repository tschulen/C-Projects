/*
 ============================================================================
 Name        : TschulenbergDNASequenceCounter.c
 Author      : Tyler Schulenberg
 Version     : 1.0
 Copyright   : Your copyright notice
 Description : Takes a DNA sequence and counts the 4 types of nucleotides
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void) {
	int nucleotideCounts[4]; // array for counting specific nucleotides
	int TotalCount = 0; // counts total amount of nucleotides in sequence
	FILE *DNAFile;
	char DnaSequence[80000]; // array to hold the dna sequence
	int count = 0; // count for reading in characters into dna sequence array
	char x; // char for transfering charaters from file into array
	int t; // switch statement loop count declaration

	DNAFile = fopen("dna.txt", "r");
/* loops through entire file and inputs characters into array */
	while (fscanf(DNAFile, "%c", &x) != EOF) {
		TotalCount++;
		DnaSequence[count] = x;
		count++;
	}
	TotalCount--; // adjusts total count to fix the last end of file loop run through.
/* switch statement for counting nucleotides */
	for (t = 0; t <= TotalCount; t++) {
		char c;
		c = DnaSequence[t];
		switch (c) {
		case 'A':
			nucleotideCounts[0]++; // counts adenine
			break;
		case 'G':
			nucleotideCounts[1]++; // counts guanine
			break;
		case 'C':
			nucleotideCounts[2]++; // counts cytosine
			break;
		case 'T':
			nucleotideCounts[3]++; // counts thymine
			break;
		default:
			break;
		}
	}
	printf(
			"Out of the %d nucleotides in the sequence, there are %d adenine, %d guanine, %d cytosine, and %d thymine.",
			TotalCount, nucleotideCounts[0], nucleotideCounts[1],
			nucleotideCounts[2], nucleotideCounts[3]);

	return EXIT_SUCCESS;
}

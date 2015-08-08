/*
 ============================================================================
 Name        : HtmlEstimater.c
 Author      : Tyler Schulenberg
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

long estimateImageContent(char *html, int *pNumberOfImages);

int main(void) {

	FILE *HTMLFile;
	char Fname[20];
	char html[80000];
	int pNumberofImages;
	int length = 0;
	char holder;
	long pixels;
	//char *phtml;
	int *test;
	int i;
	/*receives name of file from user and edits it to be used by copying routine*/
	printf("Please enter the name of the file");
	fgets(Fname, 20, stdin);
	for (i = 0; i < 20; i++) {
		if (Fname[i] == '\n') {
			Fname[i] = '\0';
			break;
		}
	}
	/*reads and copies file into html string */
	HTMLFile = fopen(Fname, "r");
	while (fscanf(HTMLFile, "%c", &holder) != EOF) {
		html[length] = tolower(holder);
		length++;
	}
	fclose(HTMLFile);

	test = &length;
	pixels = estimateImageContent(&html, test);
	printf("The inputed file is %s", Fname);
	printf("The total image area of the pictures is %ld pixels", pixels);
}

long estimateImageContent(char* html, int *pNumberOfImages) {
	int imagecount = 0;
	int height = 0;
	int width = 0;
	int sum = 0; // sum of all pixels
	int i; // loop counter
	char* Background;
	Background = html;
	Background = strstr(html, "background");
	do {
		html = strstr(html, "<img"); // finds <img
		imagecount++; // counts image
		*html++; //moves pointer forward so method goes to next image on loop

		html = strstr(html, "width="); //finds width
		for (i = 0; i < 6; i++) //steps 6 spaces forward to the number
			*html++;

		if (isdigit(*html) == 0) //checks to see if " is before number
			*html++; // if so move pointer up 1
		width = atoi(html); // if at number convert to integer


		html = strstr(html, "height="); //finds height
		for (i = 0; i < 7; i++) //steps forward 7 spaces to get to number
			*html++;
		if (isdigit(*html) == 0) // checks to see if " enclose number
			*html++;
		height = atoi(html); // if converts height to integer

		sum = sum + (width * height);
	} while (strstr(html, "<img") != NULL);

	return sum;
}

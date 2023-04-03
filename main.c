/** \file main.c
	\brief reading a string and computing some stats

	Details.
*/

#include "fileIO.h"
#include "stringlist.h"
#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include "stringslib.h"






#define STR_SIZE 5000  //per essere uguale alla struct node


int main() {


	
	int* hist;
	char mos;
	int occurrences;
	char tosearch;
	int rv;
	int counter = 1;
	int choice = 0;
	char pathDir[STR_SIZE];
	printf("Enter path file to read lines from: ");
	gets_s(pathDir, STR_SIZE);
	if (gets_s == NULL) {
		printf("Error: couldn't write path in buffer");
		return -1;
	}
	printf("You entered %s\nResults: \n\n", pathDir);
	strtoken* startList = ReadLinesFromFile(pathDir);
	strtoken* temp = startList;

	if (startList == NULL){
		printf("Error: list of strings returned NULL");
		return -1;
	}
	while (temp != NULL) {
		printf("-%d: %s\n", counter, temp->token);
		counter++;
		temp = temp->next;
	}
	

	printf("\nEnter which string to compute stat: ");
	scanf_s("%d", &choice);

	if (choice <= 0 || choice > counter) {
		printf("Error: input correct choice");
		return -1;
	}
	counter = 1;
	while (counter < choice) {
		startList = startList->next;
		counter++;
	}

	hist = Shist(startList->token, STR_SIZE);
	if (hist == NULL) {
		printf("ERROR in Main: cannot compute histogram\n");
		return -1;

	}

	rv = MOSstring(hist, &mos, &occurrences);
	if (rv < 0) {
		printf("ERROR in Main: cannot compute most occurring symbol\n");
		return -1;
	}

	printf("The most occurring symbol is '%c' = %d times\n", mos, occurrences);

	occurrences = AOstring(hist);
	if (occurrences < 0) {
		printf("ERROR in Main: cannot compute the occurrences of alphabet symbols\n");
		return -1;
	}
	printf("The string includes %d alphabet characters\n", occurrences);

	occurrences = DOstring(hist);
	if (occurrences < 0) {
		printf("ERROR in Main: cannot compute the occurrences of digits\n");
		return -1;
	}
	printf("The string includes %d digits\n", occurrences);


	printf("Enter a symbol: ");
	getchar();
	tosearch = getchar();
	occurrences = SOstring(hist, tosearch);
	if (occurrences < 0) {
		printf("ERROR in Main: cannot compute the occurrences of the symbol\n");
		return -1;

	}

	printf("Symbol -%c- appears %d times.", tosearch, occurrences);

	if (hist != NULL)
		free(hist);

	return 0;
}
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






#define STR_SIZE 1000


int main() {


	char str[STR_SIZE];
	int* hist;
	char mos;
	int occurrences;
	char tosearch;
	int rv;
	//strtoken* startList = ReadLinesFromFile("C:\\Users\\matte\\Desktop\\Lab info\\Progetti\\strings_pg_v2\\strings_pg_v2\\test.txt");

	printf("Enter text: ");
	if (fgets(str, STR_SIZE, stdin) == NULL) {
		printf("ERROR in Main: cannot read input text\n");
		return -1;

	}

	str[strcspn(str, "\n")] = 0; // removes EOL from the string

	printf("\nstring: %s\n", str);

	hist = Shist(str, STR_SIZE);
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
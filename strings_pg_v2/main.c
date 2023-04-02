#include "fileIO.h"
#include "stringlist.h"
#include <stdio.h>

#define _CRT_SECURE_NO_WARNINGS 

int main () {
	//FILE* file= OpenFile ("C:\\Users\\matte\\Desktop\\Lab info\\Progetti\\strings_pg_v2\\strings_pg_v2\\test.txt", "r");
	strtoken* startList = ReadLinesFromFile("C:\\Users\\matte\\Desktop\\Lab info\\Progetti\\strings_pg_v2\\strings_pg_v2\\test.txt");
	WriteToFile( "C:\\Users\\matte\\Desktop\\Lab info\\Progetti\\strings_pg_v2\\strings_pg_v2\\TARGET.txt", startList);
	return 0;


}
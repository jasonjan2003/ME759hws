/*
 ============================================================================
 Name        : problem2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
	if( argc < 2 ){
		printf("%d", 0);
		return EXIT_SUCCESS;
	}
	char argString[256];
	strcpy(argString,argv[1]);

	printf("%d\n", strlen(argString));
	return EXIT_SUCCESS;
}

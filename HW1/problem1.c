/*
 ============================================================================
 Name        : problem1.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CHAR 12

int main(void) {

	char digit[MAX_CHAR];
	FILE *fp;	// the file ptr
	fp = fopen("./problem1.txt","r");	//open file
	if(fp == NULL) {
	      perror("Error opening file");
	      return(-1);
	   }
	fgets(digit, MAX_CHAR-1, fp);		// read line
	fclose(fp);							// close file

	char *prefix = "Hello! I’m student";
	printf("%s %s.\n",prefix,digit+strlen(digit)-4);

	return EXIT_SUCCESS;
}

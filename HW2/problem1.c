#include <stdio.h>
#include <stdlib.h>

int main(void){
	
	int i;						// current value read from file
	FILE *fp;					// the file

	// open the file
	fp = fopen("./problem1.in","r");

	// Check if file opened okay
	if( fp == NULL ){
		perror("error opening file.");
		return(-1);
	}

	fscanf (fp, "%d", &i);		// first line contains number of numbers in list
	printf("%d\n", i);			// task 1: print out # of integers read in
	int arr[i];					// declare int array with that many elements

	// read in rest of list
	int val;
	for (int a = 0; a<i; a++)
	{
		if( fscanf(fp, "%d\n", &val) != EOF ){
			arr[a] = val;
			printf("%d\n", arr[a]);
		}
		
	}
	fclose(fp);


	return 0;
}
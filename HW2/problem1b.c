#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int size;						// list size
int cmpfunc (const void* p1, const void* p2);

int main(void){
	
	FILE *fp;					// the file

	// open the file
	fp = fopen("./problem1.in","r");

	// Check if file opened okay
	if( fp == NULL ){
		perror("error opening file.");
		return(-1);
	}

	fscanf (fp, "%d", &size);		// first line contains number of numbers in list
	printf("%d\n", size);			// task 1: print out # of integers read in
	int arr[size];					// declare int array with that many elements

	// read in rest of list
	int val;
	for (int i = 0; i<size; i++)
	{
		if( fscanf(fp, "%d\n", &val) != EOF ){
			arr[i] = val;
			//printf("%d\n", arr[i]);
		}
		
	}
	fclose(fp);					// close file
	//int count = size;			// count times of sort
	clock_t begin = clock();	// start time
	qsort(arr, size, sizeof(int), cmpfunc);
	clock_t end = clock();		// end time
	// print time in [ms]
	printf("%.10f\n",(double)(end-begin)/CLOCKS_PER_SEC*1000.0);

	fp = fopen("./problem1.out", "w");	// create/replace output file
	if( fp == NULL ){					// check for fopen errors
		perror("error opening file.");
		return(-1);
	}
	for (int i = 0; i<size; i++)		// print in file
		fprintf(fp, "%d\n", arr[i]);		// line after line
	return 0;
}
int cmpfunc(const void* p1, const void* p2){
	return ( *(int*)p1 - *(int*)p2 );
}
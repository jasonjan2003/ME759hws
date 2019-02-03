#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void exclusiveScanAdd(int arr[], int out[]);
int size;						// list size

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
	int arr[size], out[size];		// declare int array with that many elements

	// read in rest of list
	int val;
	for (int i = 0; i<size; i++)
	{
		if( fscanf(fp, "%d\n", &val) != EOF ){
			arr[i] = val;
		}
	}
	fclose(fp);					// close file
	clock_t begin = clock();	// start time
	exclusiveScanAdd(arr,out);	// Exclusive scan add
	clock_t end = clock();		// end time
	// print time in [ms]
	printf("%f\n",(double)(end-begin)/CLOCKS_PER_SEC*1000.0);
	printf("%d\n", out[size-1]);// last element in scanned array

	fp = fopen("./problem2.out", "w");	// create/replace output file
	if( fp == NULL ){					// check for fopen errors
		perror("error opening file.");
		return(-1);
	}
	for (int i = 0; i<size; i++)		// print in file
		fprintf(fp, "%d\n", out[i]);	// line after line
	return 0;
}

void exclusiveScanAdd(int arr[], int out[]){

	out[0] = 0;
	for (int i = 0; i < size-1; i++)
	{
		out[i+1]=out[i]+arr[i];
	}

}

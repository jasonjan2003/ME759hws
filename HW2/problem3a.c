#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>


signed short randNum(void);
int main(int argc, char const *argv[])
{
	
	FILE *fp;							// the file
	time_t t;

	// open the file
	fp = fopen("./problem3.dat","w");

	// Check if file opened okay
	if( fp == NULL ){
		perror("error opening file.");
		return(-1);
	}

	// Init rand
	srand((unsigned) time(&t));

	// Retrieve image size
	int size = atoi(argv[1]);
	for (int i = 0; i < size; i++)
	{
		fprintf(fp, "%d\n", randNum());
	}


}
signed short randNum(void){
	return (rand() & 1) ? 1 : -1;
}


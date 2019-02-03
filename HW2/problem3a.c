#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>


signed short randNum(void);
void randNumGen(void);
FILE *fp;	// the file
int size;
int main(int argc, char const *argv[])
{
	
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
	size = atoi(argv[1]);
	randNumGen();
	fprintf(fp, "\n ");

	// Retrieve feature size
	size = atoi(argv[2]);
	randNumGen();

	// Close file
	fclose(fp);

	return 0;

}
signed short randNum(void){
	return (rand() & 1) ? 1 : -1;
}
void randNumGen(void){
	for (int i = 0; i < size; i++)
		fprintf(fp, "%d ", randNum());

}

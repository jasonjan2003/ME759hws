#include <stdio.h>
#include <stdlib.h>

FILE *fp;
const int MAX_IMAGE_SIZE=1024*1024;
const int MAX_FEATURE_SIZE=9*9;
int main(void)
{
	signed short *img  = (signed short*) malloc(sizeof(signed short) * MAX_IMAGE_SIZE);
	signed short *feat = (signed short*) malloc(sizeof(signed short) * MAX_FEATURE_SIZE);
	if( !img || !feat ){
		perror("Malloc failed");
		error(1);
	}

	// open data file
	//fp = fopen("./problem3.dat","r");



	return 0;
}
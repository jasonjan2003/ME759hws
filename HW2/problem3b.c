#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
FILE *fp;
size_t img_dim=5;				// guess dimension of image
size_t fet_dim=9;				// guess dimension of feature
size_t squareDim(size_t dim);	// prototype square function
int charArrayToValue(char *line, signed short *arr, size_t *dim);

int main(void)
{
	

	// open data file
	fp = fopen("./problem3.dat","r");

	// read first line
	size_t lineLength = 0;						// length of line
	char *line = NULL;							// file line array
	if(getline(&line, &lineLength, fp) == 0){	// get first line
		perror("getline");
		exit(EXIT_FAILURE);
	}
	img_dim = (size_t) sqrt(lineLength / 2);	// estimate of img dimension


	signed short *img = (signed short*) malloc(sizeof(signed short) * squareDim(img_dim));
	if( !img ){
		perror("Malloc failed");
		exit(EXIT_FAILURE);
	}
	//scan every value in line
	int imgCount = charArrayToValue(line, img, &img_dim);

	
	// read 2nd line
	lineLength = 0;							// length of line
	line = NULL;							// file line array
	if(getline(&line, &lineLength, fp) == 0){	// get first line
		perror("getline");
		exit(EXIT_FAILURE);
	}

	signed short *fet = (signed short*) malloc(sizeof(signed short) * squareDim(fet_dim));
	
	//scan every value in line
	int fetCount = charArrayToValue(line, fet, &fet_dim);

	free(line);
	free(img);
	free(fet);
	img = fet = NULL;
	fclose(fp);
	return 0;
}

size_t squareDim(size_t dim){
	return (size_t) pow(dim,2);
}

int charArrayToValue(char *line, signed short *arr, size_t *dim){

	int currValue = 0;		// current value holder
	int arrCount = 0;		// count values already read
	int skip = 0;			// chars to skip
	while( sscanf(line+skip,"%d", &currValue)){
		
		// if arr is full
		if( arrCount == squareDim((size_t)&dim)){

			// create temporary realloc pointer
			*dim=*dim + 1;	// increment dimension
			signed short *arr_temp = realloc(arr, squareDim((size_t)*dim));
			if( arr_temp == NULL ){
				perror("realloc line 1");
				exit(EXIT_FAILURE);
			}
			arr = arr_temp;	// replace img with the larger img_temp
		}
		arr[arrCount++] = currValue;
		skip = skip + (currValue ==1 ? 2 : 3);
	}
	return arrCount;
}
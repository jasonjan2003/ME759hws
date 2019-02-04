#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
FILE *fp;
size_t img_dim=5;				// guess dimension of image
size_t fet_dim=9;				// guess dimension of feature
size_t out_dim=1;
size_t squareDim(size_t dim);	// prototype square function
int charArrayToValue(char *line, signed short *arr, size_t *dim);

int main(void)
{
	
	int imgCount, fetCount;
	signed short *img = NULL;
	signed short *fet = NULL;

	// open data file
	fp = fopen("./problem3.dat","r");

	// ------- read first line ------
	size_t lineLength = 0;						// length of line
	char *line = NULL;							// file line array
	if(getline(&line, &lineLength, fp) == 0){	// get first line
		perror("getline");
		exit(EXIT_FAILURE);
	}
	img_dim = (size_t) sqrt(lineLength / 2);	// estimate of img dimension

	img = malloc(sizeof(signed short) * squareDim(img_dim));
	if( !img ){
		perror("Malloc failed");
		exit(EXIT_FAILURE);
	}
	//scan every value in line
	imgCount = charArrayToValue(line, img, &img_dim);
	// -----------
	//
	
	// ------ read 2nd line ------
	lineLength = 0;							// length of line
	line = NULL;							// file line array
	if(getline(&line, &lineLength, fp) == 0){	// get first line
		perror("getline");
		exit(EXIT_FAILURE);
	}

	fet = malloc(sizeof(signed short) * squareDim(fet_dim));
	
	//scan every value in line
	fetCount = charArrayToValue(line, fet, &fet_dim);
	// ----------
	//

	// Don't need the char line or file anymore
	free(line);
	fclose(fp);

	// Calculate and set output array size
	out_dim = img_dim-fet_dim+1;
	int out[squareDim(out_dim)];

	// Start matching
	for (int i = 0; i < squareDim(out_dim); i++){
		int topLeftIndex_X = i/out_dim;
		int topLeftIndex_Y = i%out_dim;
		int topLeftIndex = topLeftIndex_X*img_dim + topLeftIndex_Y;
		int sum = 0;
		for (int fetIndex = 0; fetIndex < fetCount; fetIndex++)
		{
			int imgShift = fetIndex/fet_dim*img_dim + fetIndex%fet_dim;
			sum += img[topLeftIndex + imgShift] * fet[fetIndex];
		}
		out[i] = sum;
	}
	
	
	free(img);
	free(fet);

	return 0;
}

size_t squareDim(size_t dim){
	return (size_t) pow(dim,2);
}

int charArrayToValue(char *line, signed short *arr, size_t *dim){

	int currValue = 0;		// current value holder
	int arrCount = 0;		// count values already read
	int skip = 0;			// chars to skip
	while( sscanf(line+skip,"%d", &currValue) > 0){
		
		// if arr is full
		if( arrCount == squareDim((size_t)*dim)){

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
		skip += (currValue ==1 ? 2 : 3);
	}

	// Realloc to proper size
	signed short *arr_temp = realloc(arr, (size_t)arrCount);
	if( arr_temp == NULL ){
		perror("realloc line 1");
		exit(EXIT_FAILURE);
	}
	arr = arr_temp;
	*dim=sqrt(arrCount);
	return sqrt(arrCount);
}
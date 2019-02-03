#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
FILE *fp;
size_t img_dim=5;				// guess dimension of image
size_t fet_dim=9;				// guess dimension of feature
size_t squareDim(size_t dim);	// prototype square function


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

	int currValue = 0;		// current value holder
	int imgCount = 0;		// count values already read
	signed short *img = (signed short*) malloc(sizeof(signed short) * squareDim(img_dim));
	if( !img ){
		perror("Malloc failed");
		exit(EXIT_FAILURE);
	}
	//scan every value in line
	int skip = 0;
	while( sscanf(line+skip,"%d", &currValue)){
		
		// if img is full
		if( imgCount == squareDim(img_dim)){

			// create temporary realloc pointer
			signed short *img_temp = realloc(img, squareDim(img_dim+1));
			if( img_temp == NULL ){
				perror("realloc line 1");
				exit(EXIT_FAILURE);
			}
			img = img_temp;	// replace img with the larger img_temp
		}
		img[imgCount++] = currValue;
		skip = skip + (currValue ==1 ? 2 : 3);
	}
	
	signed short *fet = (signed short*) malloc(sizeof(signed short) * squareDim(fet_dim));
	
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
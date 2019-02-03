#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

int main(int argc, char **argv){

	if (argc < 2){
		perror("Missing exponent input");
		return -1;
	}
	int exp = atoi(argv[1]);
	int limit = (1 << exp);
	time_t t;
	FILE *fp;

	fp = fopen("./problem2.in", "w");
	fprintf(fp, "%d\n", limit);

	// Init rand
	srand((unsigned) time(&t));

	for(int i=0; i<limit; i++){
		fprintf(fp, "%d\n", (rand()%21)-10);	//-10 to 10
	}

	return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main(void){
	int i,n;
	//char * buffer;

	printf ("How long do you want the string? ");
	scanf (" %d", &i);
	printf("%d\n", i);

	int arr[i];
	for (int a = 0; a<i; ++i)
	{
		arr[a]=a;
		printf("%d\n", arr[a]);
	}

	return 0;
}
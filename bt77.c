#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(int argc, char *argv[])
{
	char *curval = (char *)malloc(sizeof(char)*1000);
	curval = getenv(argv[1]);
	printf("%s\n", curval);
	setenv(argv[1], argv[2], 1);
	curval = getenv(argv[1]);
	printf("%s\n", curval);	
	return 0;
}	

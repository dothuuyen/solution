#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main(int argc, char *argv[])
{
	char *tutimkiem = (char *)malloc(sizeof(char)*100);	
	tutimkiem = argv[1];
	char *filetimkiem = (char *)malloc(sizeof(char)*100);
	filetimkiem = argv[2];
	char *noidungfile = (char *)malloc(sizeof(char)*1000);
	FILE *file;
	file = fopen(filetimkiem , "r");			
	if (file == NULL) {
		printf("File khong ton tai");
		exit(0);
	}	
	fread(noidungfile, 1000, 1, file);
	char *noidungfile2 = (char *)malloc(sizeof(char)*1000);
	noidungfile2 = strtok(noidungfile, "\n");
	while(noidungfile2 != NULL) {
		if (strstr(noidungfile2, tutimkiem) > 0) {
			printf("%s\n",noidungfile2);		
		}	
		noidungfile2 = strtok(NULL, "\n");
	}
	return 0;
}

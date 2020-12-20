#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(int argc, char *argv[]) 
{
	char *tenfile = (char *)malloc(sizeof(char)*100);	

	if (strcmp(argv[1],"a") == 0) 
	{
		printf("Nhap ten file\n");
		scanf("%s", tenfile);
	}
	else if (strcmp(argv[1], "b") == 0) 
	{
		tenfile = argv[2];
	}
	FILE *file = fopen(tenfile, "r");
	if (file == NULL) {
		printf("File khong ton tai\n");
	exit(0);
	}	
	char *noidungfile = (char *)malloc(sizeof(char)*1000);
	fread(noidungfile, 1000, 1, file);
	printf("%s", noidungfile);	
	fclose(file);
	return 0;
}


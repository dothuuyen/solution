#include<stdio.h>
#include<stdlib.h>
int main(int argc, char *argv[]) 
{
	FILE *file;
	file = fopen("vd.txt", "r");
	fseek(file, 0, SEEK_END);
	int size = ftell(file);	
	fseek(file, 0, 0);	
	int dem = 0;	
	char c;
	while(dem < 3)
	{	
		c = getc(file);	
		if (c=='\n') dem++;
	}	
	char *s = (char *)malloc(sizeof(char) * 1000);
	fread(s, size, 1, file);
	printf("%s", s);
	fclose(file);
	return 0;
}

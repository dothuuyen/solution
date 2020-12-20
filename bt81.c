#include<stdio.h>
#include<string.h>
int main(int argc, char *argv[])
{
	char s[100];
	FILE *file, *file1;
	file = fopen("vidu.doc","w");	
	file1 = fopen("vd.txt","r");	
	if (strcmp(argv[1],"a") == 0) 
	{
		printf("Nhap noi dung:\n");	
		fgets(s, 100, stdin);	
		fwrite(s, strlen(s) + 1, 1, file); 
	}
	else if (strcmp(argv[1],"b") == 0) 
	{
		fread(s, 100, 1, file1);
		fwrite(s, strlen(s) + 1, 1, file);
	}
	fclose(file1); 		
	fclose(file);
	return 0;
}







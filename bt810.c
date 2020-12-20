#include<stdio.h>
#include<stdlib.h>
int main(int argc, char *argv[]) 
{
	printf("Nhap ten file muon dinh huong lai loi ra\n");
	char *tenfile1 = (char *)malloc(sizeof(char)*100);
	scanf("%s", tenfile1);
	printf("Nhap ten file dich\n");
	char *tenfile2 = (char *)malloc(sizeof(char)*100);
	scanf("%s", tenfile2);
	char *buffer = (char *)malloc(sizeof(char)*1000);
	FILE *file1, *file2;
	file1 = fopen(tenfile1, "r");
	fread(buffer, 1000, 1, file1);
	fclose(file1);
	file2 = fopen(tenfile2, "w");
	fwrite(buffer, 1000, 1, file2);
	fclose(file2);
	return 0;
}	

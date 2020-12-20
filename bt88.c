#include<stdio.h>
#include<stdlib.h>
int main(int argc, char *argv[])
{
	char *buffer = (char *)malloc(sizeof(char)*100);
	printf("Nhap ten file\n");	
	scanf("%s", buffer);	
	if (remove(buffer)==0) {
		printf("Xoa thanh cong!\n");
	}
	else printf("Khong the xoa file!\n");	
	return 0;
}

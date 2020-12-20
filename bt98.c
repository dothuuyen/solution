#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
int main(int argc, char *argv[])
{
	int se;	
	if (strcmp(argv[1], "a") == 0) {
		printf("Nhap so giay\n"); 
		scanf("%d", &se);
	}
	else if (strcmp(argv[1], "b") == 0) {
		se = atoi(argv[2]);	
	}
	while(1) {
		printf("Working ...\n");
		sleep(se);
	}
	return 0;
}

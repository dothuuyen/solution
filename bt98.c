#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>
#include<signal.h>
int stop = 0;
void handle_sigint(int sig)
{
	printf("Ket thuc\n");	
	stop = 1;
}
int main(int argc, char *argv[])
{
	signal(SIGINT, handle_sigint);	
	int se;	
	if (strcmp(argv[1], "a") == 0) {
		printf("Nhap so giay\n"); 
		scanf("%d", &se);
	}
	else if (strcmp(argv[1], "b") == 0) {
		se = atoi(argv[2]);	
	}
	while(stop == 0) {
		sleep(se);	
		printf("Working ...\n");
	}
	return 0;
}

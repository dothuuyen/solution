#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
int main()
{
	pid_t child1, child2;
	child1 = fork();
	if (child1 == 0) {
		printf("Ket thuc process con %d, sinh ra tu process %d\n", getpid(), getppid());	
		exit(0);	
	}
	else {
		child2 = fork();
		if (child2 == 0) {
			printf("Ket thuc process con %d, sinh ra tu process %d\n", getpid(), getppid());	
			exit(0);	
		}
		else {
			wait(NULL);	
			printf("Ket thuc process cha %d\n", getpid());
		}	
	}		
}	

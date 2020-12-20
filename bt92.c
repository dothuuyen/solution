#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
int main(int argc, char *argv[])
{
	pid_t ls_process, date_process; 
	ls_process = fork();
	if (ls_process == 0) {
		printf("Tien trinh con thuc thi lenh ls, id la %d, duoc tao ra tu tien trinh %d\n", getpid(), getppid());  	
		execlp("ls", "ls", NULL);	
		exit(0);	
	}
	else {
		date_process = fork();
		if (date_process == 0) {
			printf("Tien trinh con thuc thi lenh date, id la %d, duoc tao ra tu tien trinh %d\n", getpid(), getppid()); 
			execlp("date", "date", NULL);
			exit(0);	
		}
		else {
			printf("Day la tien trinh shell me, id la %d\n", getpid());	
			wait(NULL);	
		}	
	}	
} 

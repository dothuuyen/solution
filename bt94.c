#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(int argc, char *argv[])
{
	int pipefd[2];
	pid_t pro1, pro2;
	pipe(pipefd);	
	pro1 = fork();
	if (pro1 == 0) {
		dup2(pipefd[1], 1);
		close(pipefd[0]);
		close(pipefd[1]);
		execlp(argv[1], argv[1], NULL);
	}
	else {
		pro2 = fork();
		if (pro2 == 0) {
			dup2(pipefd[0], 0);
			close(pipefd[0]);
			close(pipefd[1]);
			execlp(argv[2], argv[2], NULL);
		}
		else {
			exit(0);
		}
	}
}	


#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>
#include<sys/stat.h>
#include<fcntl.h>
#define MAX 1000 
int main(void)
{
	char *motafile = (char *)malloc(sizeof(char)*MAX);	
	fgets(motafile, MAX , stdin);	
	motafile = strtok(motafile, "\n");	
	char *inputfile = (char *)malloc(sizeof(char)*MAX);	
	char *outputfile = (char *)malloc(sizeof(char)*MAX);	
	char *cmd = (char *)malloc(sizeof(char)*MAX);	
	cmd = strtok(motafile, " <> ");	
	inputfile = strtok(NULL, " <> ");
	outputfile = strtok(NULL, " <> ");		
	char *str[] = {cmd, inputfile, 0};
	int fd = open(outputfile, O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR );	
	dup2(fd, 1);	
	execvp(str[0], str);	
	return 0;
}

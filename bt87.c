#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
int main(int argc, char *argv[])
{
	char *cwd = (char *)malloc(sizeof(char)*1000);
	if (getcwd(cwd, 300)!=NULL) {
		printf("Current directory:%s\n", cwd);
	}
	else printf("Cant get current directory\n");
	char *dir_path = (char *)malloc(sizeof(char)*1000);
	printf("Nhap duong dan thu muc muon chuyen den\n");
	scanf("%s", dir_path);	
	if (chdir(dir_path) == 0) {
		if (getcwd(cwd, 300)!=NULL) {
               		 printf("Current directory:%s\n", cwd);
       		}
        	else printf("Cant get current directory\n");
	}
	else printf("Cant move to that directory\n");	
	return 0;
}			


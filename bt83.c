#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<unistd.h>
#include<pwd.h>
int main(int argc, char *argv[])
{
	printf("Nhap ten file\n");
	char *tenfile = (char *)malloc(sizeof(char)*100);
	scanf("%s", tenfile);	
	FILE *file = fopen(tenfile, "r");
	if (file==NULL) {
		printf("Khong co file\n");
		exit(0);	
	}
	else {
		if (chmod(tenfile, S_IRUSR|S_IWUSR) == 0) {
			printf("Change permission successfully!\n");
		}
		struct passwd *pwd;	
		pwd = getpwnam("minhth");
		if (chown(tenfile, pwd->pw_uid, -1) == 0) {
			printf("Change owner successfully!\n");
		}
	}
	fclose(file);			
	return 0;
}	

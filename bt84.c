#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
int main(int argc, char *argv[])
{
	char *tenfile = (char *)malloc(sizeof(char)*100);
	printf("Nhap ten file\n");
	scanf("%s", tenfile);	
	struct stat stats;
	if (stat(tenfile, &stats) == 0) {
		printf("File co kich thuoc la %ld\n", stats.st_size);	
		mode_t permode = stats.st_mode;	
		printf("User co cac quyen:\n");	
		if (permode & S_IRUSR) printf("doc\n");
		if (permode & S_IWUSR) printf("viet\n");
		if (permode & S_IXUSR) printf("thuc thi\n");	
		printf("Group co cac quyen:\n");
		if (permode & S_IRGRP) printf("doc\n");
		if (permode & S_IWGRP) printf("viet\n");
		if (permode & S_IXGRP) printf("thuc thi\n");	
		printf("Nhung nguoi khac co quyen:\n");
		if (permode & S_IROTH) printf("doc\n");
		if (permode & S_IWOTH) printf("viet\n");
		if (permode & S_IXOTH) printf("thuc thi\n");
	}
	else printf("Cant get the size of file\n");
	return 0;
}

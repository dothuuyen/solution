#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<dirent.h>
#include<string.h>
int main(int argc, char *argv[])
{
	DIR *d;
	d = opendir(".");
	struct dirent *dir;	
	char *currentdir[500];	
	for(int i = 1 ; i < 500 ; i++) currentdir[i] = (char *)malloc(sizeof(char)*1000); 	
	int dem = 0;	
	if (d) {
		while((dir = readdir(d)) != NULL) 
		{
			dem++;
			strcpy(currentdir[dem], dir->d_name);	
		}
	}
	closedir(d);
		
	while(1) 
	{
		sleep(60);	
		d = opendir(".");
		int dem2 = 0;
		char *currentdir2[500];
		for(int i = 1; i < 500 ; i++) currentdir2[i] = (char *)malloc(sizeof(char)*1000); 
		if (d) {
			printf("cac tep vua xuat hien moi la\n");	
			while((dir = readdir(d)) != NULL) 
			{
				int kt = 0;
				for(int i = 1 ; i <= dem ; i++)
					if (strcmp(currentdir[i], dir->d_name)==0) kt=1;
				if (kt == 0) printf("%s\n", dir->d_name);
				dem2++;
				strcpy(currentdir2[dem2], dir->d_name);
			}	
		dem = dem2;
		for(int i = 1 ; i <= dem ; i++)
		currentdir[i] = currentdir2[i];
		}	
	}
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

void helper() {
	printf("SYNOPSIS\n   dir [OPTIONS] [directory]\nOPTIONS\n   -h  print a summary of options and exit\n   -l   print file size in bytes before the file name.\n");
};

int main (int argc, char **argv) {
	char l=0,c;
	char *path;
	int i=0;
	DIR *dip;
	struct dirent *dir;
	while ( (c=getopt(argc,argv,"hl")) != -1 ) {
		switch (c) {
			case 'h':
				helper();
				return;
			case 'l':
				l=1;
				break;
		}
	}
	if (optind==argc)
		path="./";
	else
		path=argv[optind];

	if ((dip = opendir(path)) == NULL) {
                perror("opendir");
                return 0;
        }
	while ((dir = readdir(dip)) != NULL) {
		if (l==1) {
			long sz;
			path=(char*)malloc(sizeof path + sizeof dir->d_name);
			strcat(path,dir->d_name);
			struct stat current;
			lstat(path,&current);
//			FILE *fp=fopen(path,"r+");
//			fseek(fp, 0, SEEK_END);
//			sz = ftell(fp);
			printf("%ld %s\n", current.st_size, dir->d_name);
		}		
		else
                	printf("%s\n", dir->d_name);
        }

}
	

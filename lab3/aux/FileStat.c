
/* sample program to illustrate the opendir(), readdir() and stat()
   system calls 

   it lists all files in the given directory, and adds an asterisk
   to each one which is a subdirectory */

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/dir.h>

#define MAX_CHARS 200

int CharsRead,Tmp;  /* number of characters read from a directory entry */
struct direct *DirEntryPtr;  /* pointer to a directory entry */
DIR *DirPtr;  /* pointer to the directory */
struct stat Stat;
char Path[MAX_CHARS];

main(argc,argv)
   int argc;  char **argv;

{  DirPtr = opendir(argv[1]);
   while (1)  {
      DirEntryPtr = readdir(DirPtr);
      if (DirEntryPtr == 0) break;  /* reached end of directory entries */
      /* process file (other than . and ..) */
      if (strcmp(DirEntryPtr->d_name,".") != 0 &&
          strcmp(DirEntryPtr->d_name,"..") != 0)  {
	     /* print file name */
	     printf("%s",DirEntryPtr->d_name);
	     /* build full path name of the file, for stat() */
	     Path[0] = 0;
	     strcat(Path,argv[1]);
	     strcat(Path,"/");
	     strcat(Path,DirEntryPtr->d_name);
             Tmp = stat(Path,&Stat); 
             /* Stat now contains lots of info about the file,
                e.g. its size, though we are not interested in
                most of that info here */
             if (S_ISDIR(Stat.st_mode)) printf("*");
             printf("\n");
      }
   }
}



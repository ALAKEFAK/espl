#include <stdio.h>
#include <stdlib.h>

struct rec {
	int x;
};
int main ( int argc, char **argv ) {
	FILE *fp1, *fp2;
	int byteNum=0;
	fp1=fopen((argv[1]),"r+");
	fp2=fopen((argv[2]),"r+");
	struct rec r;
	int b1,b2;
	while (fread(&b1,1,1,fp1)) {
		byteNum++;
		if (!(fread(&b2,1,1,fp1))) {
			printf("byte %i -%i +%i\n", byteNum,b1,b2);
			return 0;
		}
		printf("  %i   %i  \n",b1,b2);
		if (b1!=b2) {
			printf("byte %i -%i +%i\n", byteNum,b1,b2);
			return 0;
		}
	}
	if (fread(&b2,1,1,fp1))
		printf("byte %i -%i +%i\n", byteNum,b1,b2);
	return 0;
		
}

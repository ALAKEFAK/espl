#include <stdio.h>
#include <stdlib.h>


int main ( int argc, char **argv ) {
	FILE *fp1, *fp2;
	
	fp1=fopen((argv[1]),"r+");
	fp2=fopen((argv[2]),"r+");
	int lineNumber=0;
	char line1[128],line2[128];
	while (fgets(line1, 128, fp1)) {
		fgets(line2, 128, fp2);
		lineNumber++;
		char flag=1;
		if (sizeof(line1)!=sizeof(line2)) {
			printf("-%i: %s+%i: %s\n",lineNumber,line1,lineNumber,line2);
			flag=0;
		}
		else {
			int i=0;
			while (line1[i]!='\n' && line1[i]!=EOF && flag) {
				if (line1[i]!=line2[i]) {
					printf("-%i: %s+%i: %s\n",lineNumber,line1,lineNumber,line2);
					flag=0;
				}
				i++;
			}
		}
	}	
}

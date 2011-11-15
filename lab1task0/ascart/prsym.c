#include <stdlib.h>
#include <stdio.h>
#include "font.h"

void prsym(int idx) {
	int iline;
	char *(*symbol)[SYMBOL_HEIGHT] = &alphabet[idx];
	for(iline = 0; iline!=SYMBOL_HEIGHT; ++iline)
		printf("%s\n", (*symbol)[iline]);
}


int main(int argc, char **argv) {
	int i=1;	
	while (i<argc) {
		char *word=argv[i];
		int z=0;
		char c =word[0];
		while (c!=0) {
			prsym(c-32);
			z++;
			c=word[z];
		}
	++i;
	}
	return 0;
}

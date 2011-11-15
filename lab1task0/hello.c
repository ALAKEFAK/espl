 #include <stdio.h>

 /* count number of words in sentence */
 int main(int argc, char **argv) {
   int i;

   printf("There are %d words in phrase '", argc-1);

   for(i=argc-1; i!=0; --i) {

      printf("%s ", argv[i]);

   }
   printf("'.\n");

   return 0;
 }


#include <stdlib.h>
#include <string.h>
#include <stdio.h>
int main(int argc, char const *argv[])
{
	char  *s = malloc(10000);
    char *s2 = malloc(100000);
	// char *s3 =  s2;
	free(s2);
	s2 = s;
   // s = malloc(0);
   printf("djsfgdsjhfgdjfhg\n");
   system("leaks a.out");
    // while (1 );
    return 0;
}
//131062

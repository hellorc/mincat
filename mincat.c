#include <stdio.h>

void file_copy(FILE *, FILE *);

int main(int argc, char const *argv[])
{
	
	FILE *fp;

	if(argc == 1) file_copy(stdin,stdout);

	else
		while(--argc > 0)
			if( (fp = fopen(*++argv,"r")) ==NULL ) {
				printf("can't open %s\n",*argv );
				return 1;
			}

			else{
				file_copy(fp,stdout);
				fclose(fp);
			}

	return 0;
}

void file_copy(FILE * ifp, FILE *ofp)
{
	int c;

	while( (c = getc(ifp)) !=EOF ) putc(c,ofp);
}

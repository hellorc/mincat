#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//yo

short int SHOW_END=0;

void file_copy(FILE *, FILE *);

int main(int argc, char const *argv[])
{
	
	FILE *fp;

	if(argc == 1) file_copy(stdin,stdout);

	else{

		while(--argc > 0){
			if( (*++argv)[0]=='-' ){
				int s=strlen(*argv);
				while(s-- > 1) 
					switch( (*argv)[s] ){

						case 'E': SHOW_END=1; break;
						default : printf("mincat: invalid option -- '%c'\n",(*argv)[s]);exit(0);
					}
			}
			else 
				break;
        }
       
		while(argc-- > 0)
			if( (fp = fopen(*argv++,"r")) ==NULL ) {
				printf("can't open %s\n",*argv );
				return 1;
			}

			else{
				file_copy(fp,stdout);
				fclose(fp);
			}
	}

	return 0;
}

void file_copy(FILE * ifp, FILE *ofp)
{
	int c;

	while( (c = getc(ifp)) !=EOF ) {
		
		if(c=='\n') 
			if(SHOW_END)putc('$',ofp);

		putc(c,ofp);
	}

}

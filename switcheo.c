#include <stdio.h>
#include "dante.h"

int switcheo(char c){
	switch(c){
	case '0'<c<'7':
		c-='0';
		if(verEstado(led[c])==0)
			*led[VINGRESADO]=1;
		else if(verEstado(led[c]==1))
			*led[VINGRESADO]=0;

	case 't'||'T':
		for(int i=0;i<7;i++){
			if(verEstado(led[i])==0)
				*led[i]=1;
			else if(verEstado(led[i])==1)
				*led[i]=0;
		}

	case 'c'||'C':
		for(int i=0;i<7;i++){
			*led[i]=1;
		}

	case 's'||'S':
		for(int i=0;i<7;i++){
			*led[i]=0;
		}

	case 'q'||'Q':
    	printf("programa terminado");
    	return 0;

    else
    		printf("nada jeje");
		}
}

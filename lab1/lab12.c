#include <stdio.h>
#include <string.h>

int main() 
{
	int pos,i;
	char* sen = "idea without execution is worthless";
	for(i=0;i<strlen(sen);++i,++sen) {
		if(*sen=='c')
			pos=i+1;
	}
	printf("Position of c in given sentence is %d.",pos);

	return 0;
}

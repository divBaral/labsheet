#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
	char name[25];
	int roll;
	char addr[25];
	long phone;
};

void clean_stdin(void); // for flushing stdin buffer.
void sort(struct student*,int);
int main()
{
	struct  student s,st[100];
	int i=0,total;
	char another;
	FILE *fp;
	if(!(fp = fopen("student.dat","w")))perror("Can't create file");

	do{
		printf("\nEnter name,roll no,address and phone no:\n");
		scanf("%s%d%s%ld",s.name,&s.roll,s.addr,&s.phone);
		fprintf(fp, "%s %d %s %ld\n", s.name,s.roll,s.addr,s.phone);
		printf("Do you want to enter another(y/n):");
		clean_stdin();
		another = getchar();

	}while(another == 'y' || another == 'Y');

	printf("Record Saved!!\n");
	fclose(fp);
	
	printf("Do you want to recover file(y/n):");
	clean_stdin();
	another = getchar();
	if(another != 'y' && another != 'Y') return 0;
	if(!(fp=fopen("student.dat","r")))perror("can't read file");

	while(fscanf(fp,"%s%d%s%ld",st[i].name,&st[i].roll,st[i].addr,&st[i].phone)!= EOF)
		++i;

	total = i;
	sort(st,total);
	printf("\n\tRecord\n");
	printf("Name\t\tRoll no\t\tAddress\t\tPhone no\n");
	for(i=0;i<total;++i) {
		
		printf("%-20s%-5d%-20s%ld\n",st[i].name,st[i].roll,st[i].addr,st[i].phone);
	}




}
void sort(struct student* s, int size)
{
	int i,j;
	struct student temp;
	for(i=0;i<size;++i){
		for(j=i+1;j!=size; ++j) {
			if((strcmp(s[i].name,s[j].name)) > 0) {
				temp = s[i]; //intentionally using structure assignment for short despite errorprone
				s[i]=s[j];
				s[j]=temp;

			}

		}

	}

}
void clean_stdin(void)
{
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}
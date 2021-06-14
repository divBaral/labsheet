#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
	char name[25];
	int marks;
};

void clean_stdin(void); // for flushing stdin buffer.

int main()
{
	struct  student s[100];
	int i=0,total;
	char another;
	do{
		printf("\nEnter name of student and Marks in programming:\n");
		scanf("%s%d",s[i].name,&s[i].marks);
		printf("Do you want to enter another:");
		clean_stdin();
		scanf("%c",&another);
		if(another == 'y' || another == 'Y')
			++i;
		else
			break;

	}while(1);
	total = i;
	printf("\n\n\t\tMarks of students in C programming");
	printf("\nStudents\t\t\tMarks");
	for(i=0;i <= total; ++i) 
		printf("\n%-20s%d", s[i].name, s[i].marks);



}
void clean_stdin(void)
{
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}
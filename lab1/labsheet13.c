#include <stdio.h>
#include <stdlib.h>

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
		++i;

	}while(another == 'y' || another == 'Y');
	total = i;
	printf("\n\n\t\tMarks of students in C programming");
	printf("\nStudents\tMarks\n");
	for(i=0;i<total; ++i) 
		printf("%-20s%d\n", s[i].name, s[i].marks);



}
void clean_stdin(void)
{
    int c;
    do {
        c = getchar();
    } while (c != '\n' && c != EOF);
}
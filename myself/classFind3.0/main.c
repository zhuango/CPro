#include "head.h"
#include "func.h"

int main(void){
	struct Class *Student;
	int choice=0;
	
	Student = (struct Class*) malloc(sizeof(struct Class));
	Student->StudentName = (char *) malloc (20*sizeof(char));
	
	choiceM(Student);

	return 0;
}

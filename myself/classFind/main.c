#include "head.h"
#include "func.h"

int main(void){
	char *StudentName;
	int choice=0;
	StudentName = (char *) malloc (10*sizeof(char));
	
	while(1){
		printf("\n\n+++++++++++++++++++++++++++\n");
		printf("1 make new student's date\n");
		printf("2 login student to find\n");
		printf("0 exit\n");
		printf("+++++++++++++++++++++++++++\n");
		printf("\nPlease input what you want to do: ");
		scanf("%d",&choice);
		
		if(choice == 1){
			makeM(StudentName);
		}else if(choice == 2){
			loginM(StudentName);
		}else if(choice == 0){
			break;
		}else{
			printf("have no this service\n");
			continue;
		}

	}

	return 0;
}

void makeM(char *StudentName){
	printf("Please input your name : ");
	scanf("%s",StudentName);
	MakeNew(StudentName);
}

void loginM(char *StudentName){
	int choice;
	printf("Please input your name: ");
	scanf("%s",StudentName);

	while(!login(StudentName)){
		printf("Please input your name: ");
		scanf("%s",StudentName);
	}

	while(1){
		printf("\n\n+++++++++++++++++++++++++++\n");
		printf("1 Find Class\n");
		printf("2 Find Time\n");
		printf("3 Scan date\n");
		printf("0 exit\n");
		printf("+++++++++++++++++++++++++++\n\n");

		printf("Please input your choice : ");
		scanf("%d",&choice);

		switch(choice){
			case 1: findClass(StudentName); break;
			case 2: findDay(StudentName);   break;
			case 3: scan(StudentName);      break;
			case 0: break;
			default: printf("have no this choice ,try again!\n");break;
		}
		if(choice == 0)
			break;
	}
}

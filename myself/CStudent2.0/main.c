#include "head.h"
#include "func.h"
int main(int argc,char *argv[]){
	int n;					/* choice */
	char pwd[MAX_LINE];		/* string for passwd */
	char name[MAX_LINE];	/* string for name */
	while(1){

		/* print the Welcome */
		printf("\n\n****************************\n");
		printf("login as :                 *\n\n");
		printf("1 GuanLiYuan               *\n");
		printf("2 Teacher                  *\n");
		printf("3 Student                  *\n");
		printf("0 to exit !                *\n");
		printf("****************************\n");
		printf("\nAnd what you want : ");

		/*get the number, know what you want*/
		scanf("%d",&n);
		if(n == 0) exit(0);					/* 0 for exit */

		/*input the wrong number*/
		if(n > 3 || n < 0){
			printf("\n\nworing commend!\n");
			continue;
		}

		printf("name: ");					/*ask for the login info*/
		scanf("%s",name);
		printf("Password: ");
		scanf("%s",pwd);
		flush();							/* flush the '\n' */

		/* witch class people you are, GuanLiYuan or Teacther or Student*/
		if(loginWho(n,name,pwd)){
			switch(n){
				case 1:GuanLiYuan();break;
				case 2:Teacher();break;
				case 3:Student();break;
				default: break;
			}
		}else{
			printf("\n\nlogin failed!\n");
		}
	}
	return 0;
}

/* if you want to find someone, here will ask you about the student info, and goto function find() */
void findM(){
	int n;
	printf("Please input the number you want to find: ");
	scanf("%d",&n);
	find(n);
}

/* if you are a GuanLiYuan (Sorry! my English is very pool) */
void GuanLiYuan(){
	int n;
	while(1){

		/* print the choices */
		printf("\n\n*****Welocme to Students***\n");
		printf("*1 add        2 delete    *\n");
		printf("*3 print      4 find      *\n");
		printf("*5 change     0 exit      *\n");
		printf("***************************\n\n");
		printf("What you want :  ");

		/* get the choice you want, and flush the '\n' */
		n = getc(stdin) ;
		flush();

		/* wrong choice */
		if(n<'0' || n>'5'){
			printf("Please input the right comend!\n");
			continue;
		}

		/* make the decision */
		switch(n){
			case '1':add();	break;
			case '2':Delete();break;
			case '3':print();	break;
			case '4':findM();	break;
			case '5':change();
			default:break;
		}

		/* 0 for exit */
		if(n=='0'){
			printf("Bye!\n");
			break;
		}
	}
}

/* you are a thacher */
void Teacher(){
	char n;
	while(1){

		/* print the choices */
		printf("\n\n*****Welocme to Students***\n");
		printf("*1 add          2 print   *\n");
		printf("*3 find         4 change  *\n");
		printf("*0 exit                   *\n");
		printf("***************************\n\n");
		printf("What you want :  ");

		/* get the choice, flush the '\n' or other chars */
		n = getc(stdin) ;
		flush();

		/* wrong choice */
		if(n<'0' || n>'3'){
			printf("Please input the right comend!\n");
			continue;
		}

		/* make the decision */
		switch(n){
			case '1':add();	break;
			case '2':print();	break;
			case '3':findM();	break;
			case '4':change();
			default:break;
		}

		/* 0 for exit */
		if(n=='0'){
			printf("Bye!\n");
			break;
		}
	}
}	

/* you are a student */
void Student(){
	char n;
	while(1){

		/* print the choices */
		printf("\n\n*****Welocme to Students***\n");
		printf("*1 print        2 find    *\n");
		printf("*0 exit                   *\n");
		printf("***************************\n\n");
		printf("What you want :  ");

		/* get the choice from you, and flush the chars */
		n = getc(stdin) ;
		flush();

		/* wrong choices */
		if(n<'0' || n>'2'){
			printf("Please input the right comend!\n");
			continue;
		}

		/* make the decision */
		switch(n){
			case '1':print();	break;
			case '2':findM();	break;
			default:break;
		}

		/* 0 for exit */
		if(n=='0'){
			printf("Bye!\n");
			break;
		}
	}
}


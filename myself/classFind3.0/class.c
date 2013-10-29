#include "head.h"
#include "class.h"

void flash(){
	while( getchar() != '\n');
}

void MakeNew(const char *StudentName){
	FILE *ClassP;
	char FileBuffer[MAX_FILE];

	if( ( ClassP = fopen(StudentName,"r") ) != NULL){
		printf("you are here already! you don't need to add any more!\n");
		return;
	}

	AddClass(StudentName,FileBuffer,MAX_FILE);

	if( ( ClassP = fopen(StudentName,"w") ) == NULL){
		fprintf(stderr,"Oh! This too bad,the system is something wrong!\n");
		exit(EXIT_FAILURE);
	}else{
		printf("\ncreate new student %s success!!!\n",StudentName);
	}
	
	fputs(FileBuffer,ClassP);

	if(fclose(ClassP) != 0){
		fprintf(stderr,"file close error!!!");
	}


}


int AddClass(const char *StudentName,char FileBuffer[],int n){
	char line[MAX_LINE];
	int i,j;
	memset(FileBuffer,0,MAX_FILE);
	printf("\n\nNow,input your classes please!(input \"n\" mean have no class!)\n");
	
	flash();

	for(i=0;i<WEEK;i++){
		for(j=0;j<DAY;j++){
			printf("What's your class on %s %s :",week[i],day[j]);
			scanf("%s",line);
			if(strcmp(line,"n") == 0){
				strcat(FileBuffer,"no class\n");
				continue;
			}
			strcat(FileBuffer,line);
			strcat(FileBuffer,"\n");
		}
	}
	strcat(FileBuffer,"\0");

	return 1;
}

int login(const char *StudentName,const char *passwd){
	FILE *ClassP=NULL;

	if( (ClassP = fopen(StudentName,"r")) == NULL){
		fprintf(stderr,"have no student named %s! login failed,please try again!\n",StudentName);
		return 0;
	}else{
		fclose(ClassP);
		if(loginWho(StudentName,passwd)){
			printf("login success!!!\n");
			return 1;
		}else{
			return 0;
		}
	}

}

int findClass(const char *StudentName){
	int i,j,n=0;
	FILE *ClassP;
	char line[MAX_LINE];
	char ClassName[MAX_LINE];
	memset(line,0,MAX_LINE);
	memset(ClassName,0,MAX_LINE);

	if( ( ClassP = fopen(StudentName,"r")) == NULL){
		fprintf(stderr,"open file error!\n");
		exit(EXIT_FAILURE);
	}

	printf("Please input class you want to find: ");
	flash();
	fgets(ClassName,MAX_LINE,stdin);

	for(i=0;i<WEEK;i++){
		for(j=0;j<DAY;j++){
			fgets(line,MAX_LINE,ClassP);
			if(strncmp(ClassName,line,MAX_LINE) == 0){
				printf("\n\nyour have ");
				while(line[n] != '\n'){
					printf("%c",line[n]);
					n++;
				}
				printf(" class on %s %s \n",week[i],day[j]);
			}
		}
	}
	if(n == 0){
		printf("\n\nSorry! Didn't find class named %s",ClassName);
		return 0;
	}

	return 1;
}

int findDay(const char *StudentName){
	FILE *ClassP;
	int i=0,j;
	int Day,Time;
	char line[MAX_LINE];

	memset(line,0,MAX_LINE);

	if( (ClassP = fopen(StudentName,"r") ) == NULL){
		fprintf(stderr,"open file error!\n");
		exit(EXIT_FAILURE);
	}
	void choseWeek(int*);
	void choseDay (int*);

	choseWeek(&Day);
	choseDay (&Time);

	for(i=0;i<WEEK;i++){
		for(j=0;j<DAY;j++){
			fgets(line,MAX_LINE,ClassP);
			if(i == Day-1 && j == Time-1){
				i = WEEK;
				break;
			}
		}
	}

	if(strcmp(line,"no class\n") == 0){
		printf("\nHappy!  You have no class!\n");
	}else{
		printf("\nOn %s %s , you have class : %s",week[Day-1],day[Time-1],line);
	}

	fclose(ClassP);
	return 1;
}
void choseWeek(int *Day){
	while(1){
		printf("\n\n1 Monday   2 Tuesday   3 Wensday   4 Thursday   5 Friday   6 Saturday   7 Sunday\n");
		printf("\nwhich day do you want to find(input the number before the day): ");
		scanf("%d",Day);
		if(*Day < 1 || *Day > 7){
			printf("have no this day,please try again\n");
		}else{
			break;
		}
	}
}

void choseDay(int *Time){

	while(1){
		printf("\n\n1 8:00-9:35   2 10:00-11:35   3 13:30-15:05   4 15:30-17:00   5 18:00-19:35\n");
		printf("\nwhitch time do you want to find(input the number before the day): ");
		scanf("%d",Time);
		if(*Time < 1 || *Time > 5){
			printf("have no this time ,please try again\n");
		}else{
			break;
		}
	}
}

void scan(const char *StudentName){
	FILE *ClassP;
	int i,j,n=0;
	char line[MAX_LINE];

	memset(line,0,MAX_LINE);

	if( (ClassP = fopen(StudentName,"r") )== NULL){
		fprintf(stderr,"open file error\n");
		exit(EXIT_FAILURE);
	}
	
	rewind(ClassP);

	for(i=0 ;i<WEEK ;i++){
		printf("%s\n",week[i]);
		for(j=0 ; j<DAY ;j++){
			printf("\t%s",day[j]);
			fgets(line,MAX_LINE,ClassP);
			printf("\t%s",line);
		}
		printf("\n");
	}

	fclose(ClassP);
}

int length(char *str){
	int i=0;
	while(*(str+i) !='\n') i++;
	return i;
}

int check(const char *name, const char *pwd){
	FILE *fp;
	char buffer[MAX_LINE];
	char NamePwd[MAX_LINE];
	
	memset(buffer,0,MAX_LINE);
	memset(NamePwd,0,MAX_LINE);

	if( (fp = fopen(PWD,"r") ) == NULL){
		fprintf(stderr,"open pwd file error!\n");
		exit(EXIT_FAILURE);
	}

	strcat(NamePwd,name);
	strcat(NamePwd," ");
	strcat(NamePwd,pwd);
	strcat(NamePwd,"\n");

	while(fgets(buffer,MAX_LINE,fp)){
		if(strncmp(NamePwd,buffer,length(NamePwd)) == 0){
			return 1;
		}

	}

	return 0;

}

int loginWho(char *name,char *pwd){
	if( check(name, pwd) ){
		return 1;
	}

	return 0;
}

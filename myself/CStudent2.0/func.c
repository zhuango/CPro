#include "head.h"	/* include the head file */

close_file(FILE *file)
{
	if(fclose(file) != 0){
			fprintf(stderr,"Error in closing files\n");
			exit(EXIT_FAILURE);
	}
}

/* flush the buffer, eat '\n' */
void flush()
{
	char ch;
	while((ch = getc(stdin)) !='\n'){
		continue;
	}
}

/* print the student list */
void print()
{
	FILE *p;
	int ch;

	if( (p = fopen(STUDENTS,"r")) == NULL){
		printf("Can't open this file\n");
		exit(1);
	}
	while((ch = getc(p)) != EOF){		/* puts the list on terminal */
		putc(ch,stdout);
	}

	close_file(p);
}

/* 
 * student's number in the list? 
 * fp: the student list file
 * number: the number you want to be true
 *
 */
int checkNumber(FILE *fp , char *number)
{
	char line[MAX_LINE];
	while( fgets(line,MAX_LINE,fp) != NULL ){		/* get the line*/
		if(atoi(line) == atoi(number)){				/* and check the number */
			return 1;
		}
	}
	return 0;
	
}

/*
 * input the student information
 * p	: student list file
 * s	: student number
 * line	: student information
 */
int inputInfo(FILE *p,char *s,char *line)
{
	int i;
	printf("Please input the number : ");
	scanf("%s",s);									/*get the number you want to add*/
	flush();
	while(checkNumber(p,s)){						/* already in the list, return and try again */
		printf("There is a %s ,try again!\n",s);
		return 0 ;
	}
	strcat(line,s);									/* add the number into student info */
	strcat(line," ");								/* insert the space */

	printf("What is the name: ");
	scanf("%s",s);									/* get name of the student */
	flush();

	strcat(line,s);									/* add name into student info */
	strcat(line," ");

	/* three projects mark */
	for(i=0;i<3;i++){
		printf("mark%d : ",i+1);
		scanf("%s",s);
		strcat(line,s);								/* add into student info */
		strcat(line," ");
	}

	flush();
	return 1;

}

/* add a new student into list */
void add()
{
	FILE *p;			/* student list file */
	long length;		/* length of list file */
	char *file;			/* string of file */
	char line[MAX_LINE];/* one student info */
	char s[MAX_LINE];	/* student info buffer */

	int count = 0;		// 0: if the student you add was the last one  
						// 1: insert normal

	/* open the file */
	if((p = fopen(STUDENTS,"r")) == NULL){
		printf("Can't open this file\n");
		exit(1);
	}
	*line = 0;

	/* get the info of student you want to add */
	if( !inputInfo(p,s,line) ) return ;
	
	/* get the length of the file, and malloc the space for string of file */
	fseek(p,0l,SEEK_END);
	length = ftell(p);
	file = (char *) malloc(sizeof(char) * (length+MAX_LINE));
	*file = 0;
	rewind(p);

	while(fgets(s,MAX_LINE,p) != NULL){	
		/* insert the new student */
		if(count ==0 && (atoi(s) > atoi(line)) ){ 
			strcat(file,line);
			strcat(file,"\n");
			count = 1;
		}
		strcat(file,s);
	}

	/*if the number is the last one, add this student in the last postion*/
	if(count == 0){
		strcat(file,line);
		strcat(file,"\n");
	}

	/* close the file for read */
	close_file(p);

	/* open the file for writing */
	p = fopen(STUDENTS,"w");
	fputs(file,p);
	
	close_file(p);

}


/* delete the one student */
void Delete()
{
	FILE *newF;			/* student list file */
	int n=0;			/* flag 0: OK! 1: wrong type about student number */
	long length;		/* length of file */
	char *file;			/* the string of file */
	char hang[MAX_LINE];/* get one line */

	/* delete this number */
	printf("Please input the number that you want to delete: ");
	if(scanf("%d",&n) !=1){
		n=-1;/* wrong type */
	}
	flush();

	if(n==-1){return ;} /* return cause the wrong type */

	if( (newF = fopen(STUDENTS,"r")) == NULL){
		printf("Cant't open this file\n");
	}

	/* get the length of file */
	fseek(newF,0l,SEEK_END);
	length = ftell(newF);
	file = (char *) malloc(sizeof(char) * length);
	*file = 0;
	rewind(newF);


	while( fgets(hang,MAX_LINE,newF) != NULL){
		if(n == atoi(hang)){/* the student you want to delete */
			continue;
		}
		strcat(file,hang);
	}

	close_file(newF);
	
	if( (newF = fopen(STUDENTS,"w")) == NULL){
		printf("Can't open this file\n");
	}

	fputs(file,newF);
	close_file(newF);
}

/* find student
 *
 * n: the number you want to find
 */
int find(int n)
{
	FILE *pf;			/* student list file */
	char line[MAX_LINE];/* one line of file */
	flush();			/* flush the chars  */

	if( (pf = fopen(STUDENTS,"r")) == NULL){
		printf("Can't open this file\n");
	}

	/* find and print this student info */
	while(fgets(line,MAX_LINE,pf) != NULL){
		if(n == atoi(line) ){			/* find !!! */
			printf("find if !!!\n");
			puts(line);
			return 1;
		}
	}

	close_file(pf);

	printf("Sorry! Doesn't find\n");
	return 0;
}

/* change student info */
void change()
{
	FILE *pf;			/* student list file */
	int i = 0,n=0;		/*  */
	char s[MAX_LINE];	/**/
	char line[MAX_LINE];/**/
	char file[MAX_FILE];/**/
	
	/* clear the strings */
	memset(s,0,MAX_LINE);
	memset(line,0,MAX_LINE);
	memset(file,0,MAX_FILE);

	if( (pf = fopen(STUDENTS,"r")) == NULL){
		fprintf(stderr,"open file error!\n");
		exit(EXIT_FAILURE);
	}

	printf("\nPlease input the number of student what you want to change: ");/* get the number you want to change */
	scanf("%s",line);
	if(!find(atoi(line))) {/* Doesn't find  */
		return ;
	}

	while(fgets(s,MAX_LINE,pf) != NULL){
		if(atoi(line) == atoi(s)){	/* find this student */
			break;
		}
	}

	/* get this student's number and name */
	while(i != 2){
		if(s[n] == ' ') i++;
		line[n] = s[n];
		n++;
	}

	printf("\nPlease input the new marks!\n");
	/* get the new marks */
	for(i=0;i<N;i++){
		printf("mark%d : ",i+1);
		scanf("%s",s);
		strcat(line,s);
		strcat(line," ");
	}
	strcat(line,"\n");
	flush();

	rewind(pf);
	while( fgets(s,MAX_LINE,pf) != NULL){/* read file again get the string */
		if(atoi(line) == atoi(s)){
			strcpy(s,line);
		}
		strcat(file,s);
	}
	close_file(pf);

	/* write again */
	if( (pf = fopen(STUDENTS,"w") ) == NULL){
		printf("open file error!\n");
		exit(EXIT_FAILURE);
	}

	fputs(file,pf);
	close_file(pf);

}

/* cal the length of string */
int length(char *str)
{
	int i;
	for(i=0;i<MAX_LINE;i++){
		if(*(str+i) == '\n') break;
	}
	return i;
}


/*
 * check the person
 *
 * who : witch class person
 * name: client name
 * pwd : passswd
 */
int check(const char *who ,const char *name, const char *pwd)
{
	FILE *fp;				/* user list file */
	char buffer[MAX_LINE];
	char NamePwd[MAX_LINE];
	
	memset(buffer,0,MAX_LINE);
	memset(NamePwd,0,MAX_LINE);

	/* open the user file */
	if( (fp = fopen(who,"r") ) == NULL){
		fprintf(stderr,"open pwd file error!\n");
		exit(EXIT_FAILURE);
	}

	/* make the string of user info */
	strcat(NamePwd,name);
	strcat(NamePwd," ");
	strcat(NamePwd,pwd);
	strcat(NamePwd,"\n");

	if(strncmp (who,"GuanLiYuan",10) == 0){	/* you are GuanLiYuan ??? */
		fgets(buffer,MAX_LINE,fp);
		if( strncmp(NamePwd,buffer,length(NamePwd)) == 0){
			return 1;
		}
	}else{									/* or not */
		while(fgets(buffer,MAX_LINE,fp)){
			if(strncmp(NamePwd,buffer,length(NamePwd)) == 0){
				return 1;
			}
		}
	}
	return 0;
}

/* login as who */
int loginWho(int who,char *name,char *pwd)
{
	char *WHO[3] = {"GuanLiYuan" , "Teacher" , "Student"};	/* three classes */
	if( check(WHO[who-1] ,name, pwd) ){						/* login check */
		return 1;
	}
	return 0;
}

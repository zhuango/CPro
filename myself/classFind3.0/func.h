struct Class{
	char *StudentName;
	char passwd[20];
	char day[10];
	char time[10];
	char CurClass[10];
	char classes[1024];
};

void makeM(struct Class *Student){
	printf("Please input your name : ");
	scanf("%s",Student->StudentName);
	MakeNew(Student->StudentName);
}

void LoginChoice(struct Class *Student){
	int choice = 0;
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
			case 1: findClass(Student->StudentName); break;
			case 2: findDay(Student->StudentName);   break;
			case 3: scan(Student->StudentName);      break;
			case 0: break;
			default: printf("have no this choice ,try again!\n");break;
		}
		if(choice == 0)
			break;
	}
}

void loginM(struct Class *Student){
	printf("Please input your name: ");
	scanf("%s",Student->StudentName);
	printf("Password: ");
	scanf("%s",Student->passwd);

	while(!login(Student->StudentName,Student->passwd)){
		printf("\n\nlogin failed!\n\n");
		printf("Please input your name: ");
		scanf("%s",Student->StudentName);
		printf("Password: ");
		scanf("%s",Student->passwd);
	}
	LoginChoice(Student);
}

void choiceM(struct Class *Student){
	int choice = 0;
	while(1){
		printf("\n\n+++++++++++++++++++++++++++\n");
		printf("1 make new student's date\n");
		printf("2 login student to find\n");
		printf("0 exit\n");
		printf("+++++++++++++++++++++++++++\n");
		printf("\nPlease input what you want to do: ");
		scanf("%d",&choice);
		
		if(choice == 1){
			makeM(Student);
		}else if(choice == 2){
			loginM(Student);
		}else if(choice == 0){
			break;
		}else{
			printf("have no this service\n");
			continue;
		}

	}

}


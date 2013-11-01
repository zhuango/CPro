// c1.h (程序名)
 #include<string.h>
 #include<ctype.h>
 #include<malloc.h> // malloc()等
 #include<limits.h> // INT_MAX等
 #include<stdio.h> // EOF(=^Z或F6),NULL
 #include<stdlib.h> // atoi()
 #include<io.h> // eof()
 #include<math.h> // floor(),ceil(),abs()
 #include<process.h> // exit()
 #include<iostream> // cout,cin
 #include<conio.h>
 #include<Windows.h>
 // 函数结果状态代码
 #define TRUE 1
 #define FALSE 0
 #define OK 1
 #define ERROR 0
 #define INFEASIBLE -1
 // #define OVERFLOW -2 因为在math.h中已定义OVERFLOW的值为3,故去掉此行
 typedef int Status; // Status是函数的类型,其值是函数结果状态代码，如OK等
 typedef int Boolean; // Boolean是布尔类型,其值是TRUE或FALSE

 /*				while((ch=getchar()) != '\n');
				printf("\n对自动生成迷宫是否满意？(Y/N) 如不满意请输入N进行重新生成:");			
				scanf(" %c",&ch);
				i++;
			}while(('N' == ch || 'n' == ch )&&(i < 3));
			if (3 == i)
			{
				system("cls");
				printf("抱歉！程序内置的迷宫图只有%d种，您可尝试选择手动方式生成\n\n",i);
				printf("如果您有很好的构思，可将迷宫图发到我的邮箱分享：邮箱:991025437@qq.com");
				printf("\n\n9秒后自动跳转到迷宫生成方式选择界面........");
				for (i = 9; i >= 0;i--)
				{	
					printf("\b\b\b\b\b(%d秒)",i);
					Sleep(1000);
				};
				ch = 'N';
			}
			else
			{
*/	//			ch = 'Y';
//			}
//			printf("\n");
	
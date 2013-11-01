#ifndef TELEMTYPE_H//头文件保护符只能避免同一个源文件中的嵌套包含，无法避免不同源文件的中的统一头文件的重复包含。
#define TELEMTYPE_H
//定义二叉链表中的元素类型
#if ET
typedef char TElemType;
const TElemType Nil = ' ';
#define form "%c"
#else
typedef int TElemType;
const TElemType Nil = 0;//头文件中不能定义变量否则可能会因多次包含该头文件而造成重复定义的错误，但可以定义常量
#define form "%d"
#endif

#endif
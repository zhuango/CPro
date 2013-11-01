#include <stdio.h>
#include "Status.h"
#include "TElmeType.h"

enum PointerTag{Link, Thread};//PointerTag为枚举类型，Link为0,Thread为1
typedef struct BiThrNode 
{
	TElemType data;//结点的值
	BiThrNode *lchild, *rchild;//左右孩子指针
	PointerTag LTag:2;//左标志，占2bit
	PointerTag RTag:2;//右标志，占2bit 
} *BiThrTree;

void CreatBiThrTree (BiThrTree &T);//构造线索二叉树T
void InThreading (BiThrTree p);//中序遍历线索化
void InOrderThreading(BiThrTree &Thrt, BiThrTree T);//中序线索化
void InOrderTraverse_Thr (BiThrTree T, void (*vist)(TElemType));//中序遍历线索二叉树
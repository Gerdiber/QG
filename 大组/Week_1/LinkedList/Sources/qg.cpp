#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include "qg.h"
int main()
{
	int exsist = 0;//判断是否存在链表
	LLP head = NULL, tail = NULL;
	LLPP head1 = &head, tail1 = &tail;
	while (1)
	{
		printf("单链表ADT\n\n");
		printf("1.创建设定长度的链表或销毁\n");
		printf("2.往链表头部插入节点\n");
		printf("3.往链表尾部插入节点\n");
		printf("4.删除指定的节点\n");
		printf("5.遍历链表\n");
		printf("6.反转链表\n");
		printf("7.找出链表中点节点\n\n");
		printf("请选择功能: ");
		int func;
		scanf("%d", &func);//选择功能
		system("cls");
		if (func == 1)
		{
			int num;
			while (1)
			{
				system("cls");
				printf("请输入要创建的链表长度(节点个数)\n(!)若已创建链表会将原有链表销毁重新创建链表\n[输入 0 仅销毁已有链表]\n[输入 -1 取消并返回菜单]\n长度是...");
				scanf("%d", &num);
				if (num >= -1) break;//防止有聪明蛋输-1外的负数
			}
			if (num == -1);
			else CreateOrDestoryLinkList(num, head1, tail1);
			if (head == NULL) exsist = 0;
			else exsist = 1;
		}
		else if (func > 7 || func < 1) printf("妹有这功能哇!!!\n");
		else if (exsist)//已存有链表才能进行其他操作
			switch (func) {
			case 2: {AddToHead(head1); break; }
			case 3: {AddToTail(tail1); break; }
			case 4: {DeleteNode(head1, tail1); break; }
			case 5: {DisplayLL(head); break; }
			case 6: {UpsideDown(head1, tail1); break; }
			case 7: {CenterPoint(head); break; }
			}
		else if (!exsist) printf("妹有链表给我操作哇哇哇!!!\n");
		system("pause");
		system("cls");
	}
}

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <Windows.h>
#include "qg.h"
int main()
{
	NodeP root = NULL;
	NodePP root1 = &root;
	int func, exist = 0;
	while (1)
	{
		system("cls");
		printf("二叉树\n 1.初始化\n 2.插入数据\n 3.删除数据\n 4.查找数据\n");
		printf("二叉树遍历\n 5.先序遍历\n 6.中序遍历\n 7.后序遍历\n 8.层次遍历\n\n");
		printf("请选择功能:");
		if (scanf("%d", &func) != 1)
		{
			char c;
			while ((c = getchar()) != '\n');
			continue;
		}
		char c;
		while ((c = getchar()) != '\n');
		if (func < 1 || func>8) printf("无此功能\n");
		else
		{
			if (func == 1)
			{
				int n;
				system("cls");
				printf("输入 0 初始化空二叉树\n输入 输入数据个数 并输入数据初始化二叉树\n请输入...");
				while ((scanf("%d", &n)) != 1)//纠错
				{
					char c;
					while ((c = getchar()) != '\n');
					printf("输入 0 初始化空二叉树\n输入 输入数据个数 并输入数据初始化二叉树\n请输入...");
				}
				if (n == 0);
				else
				{
					int* a = new int[n];
					for (int i = 0; i < n; i++)
					{
						printf("a[%d]=", i);
						while ((scanf("%d", &a[i])) != 1)
						{
							char c;
							while ((c = getchar()) != '\n');
							printf("a[%d]=", i);
						}
						bst_insert(root1, a[i]);
					}
				}
				printf("二叉树初始化完成\n");
				exist = 1;
			}
			else if (exist == 0) printf("未初始化二叉树\n");
			else
			{
				system("cls");
				if(func>=2&&func<=4)
				{
					int data;
					printf("请输入进行该操作的节点数据:");
					while ((scanf("%d", &data)) != 1)//纠错
					{
						char c;
						while ((c = getchar()) != '\n');
						printf("请输入进行该操作的节点数据:");
					}
					if (func == 2) bst_insert(root1, data);//插入
					else if (func == 3) bst_delete(root1, data);//删除
					else if (func == 4) bst_search(root, data);//搜索
				}
				else
				{
					if (func == 5) bst_preorderR(root);//先序遍历
					else if (func == 6) bst_inorderR(root);//中序遍历
					else if (func == 7) bst_postorderR(root);//后序遍历
					else if (func == 8) bst_levelorder(root);//层次遍历
					printf("\n");
				}
			}
		}
		system("pause");
	}
}

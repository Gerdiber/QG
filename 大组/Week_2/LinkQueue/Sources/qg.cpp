#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include "qg.h"
int main()
{
	QNP front = NULL, rear = NULL;
	QNPP front1 = &front, rear1 = &rear;
	int Qlen=0, exist = 0, func = 0;//队列长度,有无队列,功能序号
	while (1)
	{
		system("cls");
		printf("链式存储的泛式队列\n");
		printf("1.初始化队列\n");
		printf("2.入队\n");
		printf("3.出队\n");
		printf("4.获取队列信息\n");
		printf("5.清空队列\n");
		printf("6.销毁队列\n\n");
		printf("请选择功能: ");
		if (scanf("%d", &func) != 1)
		{
			char c;
			while ((c = getchar()) != '\n');
			continue;//纠错
		}
		system("cls");
		if (func == 1)//初始化
		{
			system("cls");
			printf("初始化队列完成\n");
			exist = 1;
		}
		else if (func >= 2 && func <= 6)
		{
			if (exist == 1)//有队列
			{
				switch (func)
				{
				case 2: //入队
				{
					InQue(front1, rear1,&Qlen);
					break;
				}
				case 3: //出队
				{
					OutQue(front1, rear1,&Qlen);
					break;
				}
				case 4: //队列信息
				{
					QueInfo(front,Qlen);
					break;
				}
				case 5: //清空队列
				{
					ClearQue(front1,rear1,&Qlen);
					printf("队列已清空\n");
					break;
				}
				case 6: //销毁队列
				{
					ClearQue(front1,rear1,&Qlen);
					exist = 0;
					printf("队列已销毁\n");
					break;
				}
				}
			}
			else printf("没有队列进行操作,请重新选择\n");
		}
		else printf("没有该功能,请重新选择\n");
		system("pause");
	}
}

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <string.h>
#include <Windows.h>
#include "qg.h"
int main()
{
	SNP head = NULL;
	SNPP head1 = &head;
	while (1)
	{
		system("cls");
		char str[100] = {};
		int err = 0;
		printf("请输入运算表达式:\n");
		scanf("%s", str);
		for (int i = 0; i < strlen(str); i++)
		{
			if ((str[i] <= '9' && str[i] >= '0') || ((str[i] == '+' || str[i] == '-' || str[i] == '*' || str[i] == '/') && i != strlen(str) - 1)) continue;
			else if (str[i] == '(') { err++; continue; }
			else if (str[i] == ')') { err--; continue; }//过滤错误
			else { err = 1; break; }
		}
		if (err) printf("表达式有误,请重新输入\n");
		else
		{
			char str1[100] = {};//存放转化后的后缀表达式
			for (int i = 0,k=0; i < strlen(str); i++)
			{
				if (str[i] >= '0' && str[i] <= '9') { str1[k] = str[i]; k++; }//数字直接输入字符串中
				else CreateLinkStack(head1,str[i],&str1[k],&k);//运算符入栈处理
				if (i == strlen(str) - 1) ClearLinkStack(head1,&str1[k]);//最后一次则让链栈剩余运算符出栈
			}
			printf("该表达式结果为: \n");
			double result = Calculate(str1);
			printf("%lf\n", result);
			DestoryLinkStack(head1);
		}
		system("pause");
	}
}

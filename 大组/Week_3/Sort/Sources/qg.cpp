#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include "qg.h"
int main()
{
	srand(time(NULL));//已时间为随机数种子
	int* arr = NULL, * temp = NULL;//数组数据 和 临时存储用数组
	int color[15] = { 0 };//颜色排序用
	FILE* fp;//文件指针
	int length = 0;//数据数组长度
	int sel = 0;//功能选择
	while (1)
	{
		system("cls");
		printf("排序算法\n 1.插入排序\n 2.归并排序\n 3.快速排序\n 4.计数排序\n 5.基数排序\n");
		printf("数据&测试\n 6.输入新测试数据\n 7.生成新随机测试数据\n 8.读取测试数据文件\n 9.排序用时(单次大量数据)\n 10.排序用时(多次小量数据)\n");
		printf("Extra\n 11.颜色排序\n 12.寻第k大/小的数\n");
		printf("\n当前测试数据:");
		if (arr == NULL) printf("无\n");
		else 
		{
			printf("arr[%d]\n", length);
			for (int i = 0; i < length; i++) printf("%d ", arr[i]);
			printf("\n");
		}
		printf("\n请选择功能:");
		if (scanf("%d", &sel) != 1)
		{
			char c;
			while ((c = getchar()) != '\n');
			continue;
		}
		if (sel > 12 || sel < 1) continue;//纠错...
		else
		{
			system("cls");
			if ((sel > 0 && sel < 6) && length == 0)	printf("没有提供数据进行排序\n");
			else
			{
				switch (sel)
				{
				case 1: { InsertSort(arr, length); printf("已对数据进行插入排序\n"); break; }
				case 2: { MergeSort(arr,temp,0,length-1); printf("已对数据进行归并排序\n"); break; }
				case 3: { QuickSort(arr,0,length-1); printf("已对数据进行快速排序\n"); break; }
				case 4: { CountSort(arr,length); printf("已对数据进行计数排序\n"); break; }
				case 5: { RadixCountSort(arr,length); printf("已对数据进行基数排序\n"); break; }
				case 6: 
				{
					free(arr);
					free(temp);
					while (1)//输入纠错
					{
						printf("请输入新测试数据长度:");
						while (scanf("%d", &length) != 1)
						{
							char c;
							while ((c = getchar()) != '\n');
							system("cls");
							printf("请输入新测试数据长度:");
						}
						if (length > 0) break;
					}
					arr = new int[length];//创建对应长度数组
					temp = new int[length];
					for (int i = 0; i < length; i++)//输入数据
					{
						printf("arr[%d]=", i);
						while(scanf("%d", &arr[i])!=1)//纠错
						{
							char c;
							while ((c = getchar()) != '\n');
							printf("arr[%d]=", i);
						}
					}
					if ((fp = fopen("./data.txt", "w")) == NULL) printf("新数据保存为文件失败\n");
					else//保存到程序同位置
					{
						fprintf(fp,"%d\n", length);
						for (int i = 0; i < length; i++) fprintf(fp, "%d\n", arr[i]);
						fclose(fp);
						printf("新数据已保存为文件data.txt\n");
					}
					break;
				}
				case 7: 
				{
					free(arr);
					free(temp);
					while (1)//纠错
					{
						printf("请输入新测试数据长度:");
						while (scanf("%d", &length) != 1)
						{
							char c;
							while ((c = getchar()) != '\n');
							system("cls");
							printf("请输入新测试数据长度:");
						}
						if (length > 0) break;
					}
					arr = new int[length];//创建对应长度数组
					temp = new int[length];
					for (int i = 0; i < length; i++) arr[i] = rand() % 1000;//生成随机数
					printf("已生成%d个随机数据\n", length);
					if ((fp = fopen("./data.txt", "w")) == NULL) printf("新数据保存为文件失败\n");
					else//保存到程序同位置
					{
						fprintf(fp, "%d\n", length);
						for (int i = 0; i < length; i++) fprintf(fp, "%d\n", arr[i]);
						fclose(fp);
						printf("新数据已保存为文件data.txt\n");
					}
					break;
				}
				case 8: 
				{
					if ((fp = fopen("./data.txt", "r")) == NULL) printf("找不到数据文件data.txt\n");
					else//读取文件内容
					{
						free(arr);
						free(temp);
						fscanf(fp, "%d", &length);
						arr = new int[length];
						temp = new int[length];
						for (int i = 0; i < length; i++) fscanf(fp, "%d", &arr[i]);
						fclose(fp);
						printf("已从数据文件中读取数据\n");
					}
					break;
				}
				case 9: 
				{
					int f;
					printf("请选择3个数据量层次之一\n[1]10000\n[2]50000\n[3]200000\n");
					while (1)//纠错
					{
						printf("你选择的是...");
						while ((scanf("%d", &f)) != 1)
						{
							char c;
							while ((c = getchar()) != '\n');
							printf("你选择的是...");
						}
						if (f > 0 && f < 4) break;
					}
					printf("\n");
					if (f == 1) TimeCount(10000, 1);
					else if (f == 2) TimeCount(50000, 1);
					else if (f == 3) TimeCount(200000, 1);
					break;
				}
				case 10:
				{
					int n, m;
					printf("进行n个数据m次排序的计时\n");
					while (1)//纠错
					{
						printf("n=");
						while ((scanf("%d", &n)) != 1)
						{
							char c;
							while ((c = getchar()) != '\n');
							printf("n=");
						}
						if (n>0) break;
					}
					while (1)//纠错
					{
						printf("m=");
						while ((scanf("%d", &m)) != 1)
						{
							char c;
							while ((c = getchar()) != '\n');
							printf("m=");
						}
						if (m>0) break;
					}
					printf("\n");
					TimeCount(n, m);
					break;
				}
				case 11: 
				{
					for(int i=0;i<15;i++)
					{
						color[i] = rand()%100 % 3;
					}
					printf("已随机生成1组只含0,1,2元素的数组\n");
					for (int i = 0; i < 15; i++) printf("%d ", color[i]);
					printf("\n");
					ColorSort(color, 15);
					printf("颜色排序后:\n");
					for (int i = 0; i < 15; i++) printf("%d ", color[i]);
					printf("\n");
					break;
				}
				case 12: 
				{
					if (length == 0) printf("没有数据进行操作\n");
					else
					{
						int k;
						printf("在当前数组中查询第k大/小的数\n");
						while (1)
						{
							printf("请输入k的值((0,%d]内的正整数):",length);
							while (scanf("%d", &k) != 1)
							{
								char c;
								while ((c = getchar()) != '\n');
								printf("请输入k的值((0,%d]内的正整数):",length);
							}
							if (k > 0 && k <= length) break;
						}
						int max = GetKMax(arr, 0, length - 1, k);
						int min = GetKMin(arr, 0, length - 1, k);
						printf("当前数组第%d大的数为%d,第%d小的数为%d\n", k, max, k, min);
					}
					break;
				}
				}
			}
		}
		system("pause");
	}
}

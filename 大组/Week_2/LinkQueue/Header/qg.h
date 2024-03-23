typedef struct QueneNode
{
	union data
	{
		double num;
		char str[100];
	}data;
	int datatype;
	struct QueneNode* next;
}QN,*QNP,**QNPP;

void InQue(QNPP front,QNPP rear,int* sum)//入队
{
	QNP p = (QNP)malloc(sizeof(QN));
	do
	{
		printf("请选择要输入的数据:\n");
		printf("1.数值\n2.字符/字符串\n请选择:");
		if (scanf("%d", &(p->datatype)) != 1)
		{
			char c;
			while ((c = getchar()) != '\n');
		}
	} while (p->datatype != 1 && p->datatype != 2);//纠错
	if (p->datatype == 1) 
	{
		while (1)
		{
			printf("请输入数值:");
			if (scanf("%lf", &(p->data.num)) != 1)
			{
				char c;
				while ((c = getchar()) != '\n');
			}
			else { break; }
		}//纠错
	}
	else if (p->datatype == 2)
	{
		char a[5] = {};
		gets_s(a);//清空缓冲区
		printf("请输入字符/字符串:");
		gets_s(p->data.str);
	}
	if (*front == NULL)//空队列情况
	{
		*front = p;
		*rear = p;
	}
	else//有队列元素情况
	{
		(*rear)->next = p;
		*rear = p;
	}
	p->next = NULL;
	*sum = (*sum) + 1;
}

void OutQue(QNPP front,QNPP rear ,int *sum)//出队
{
	if (*front == NULL) printf("当前队列为空,无可出队节点\n");//空队列情况
	else//有队列元素情况
	{
		QNP p1 = *front;
		*front = p1->next;
		if (p1->next == NULL) *rear = NULL;//只剩一个元素出队的话
		free(p1);
		printf("已将队头元素出队\n");
		*sum = (*sum) - 1;
	}
}

void QueInfo(QNP front,int sum)//队列信息:队列长度,队列元素遍历
{
	if (front == NULL) printf("当前队列为空队列\n");
	else 
	{
		printf("当前队列有%d个元素\n", sum);
		QNP p1 = front;
		int i = 0;
		printf("队列列表:\n");
		while (p1 != NULL)//队列遍历
		{
			printf("[%d]: ",++i);
			if (p1->datatype == 1) printf("%lf\n", p1->data.num);
			else if (p1->datatype == 2) printf("%s\n", p1->data.str);
			p1 = p1->next;
		}
	}
}

void ClearQue(QNPP front,QNPP rear,int *sum)//清除队列
{
	QNP p1 = *front, p2 = *front;
	while (p1!=NULL)//遍历队列清除元素
	{
		p2 = p1->next;
		free(p1);
		p1 = p2;
	}
	*front = NULL; *rear = NULL;
	*sum = 0;
}

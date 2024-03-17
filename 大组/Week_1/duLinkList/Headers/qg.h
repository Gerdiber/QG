typedef struct LinkList {
	char str[100] = {};
	struct LinkList* next;
	struct LinkList* prior;
} LL,*LLP,**LLPP;
//LL用于创建结构体,LLP用于创建链表头尾及链表操作指针,LLPP用于在函数内修改头尾指针

char a[10] = {};//用于清除输入选项后缓冲区残余字符

void CreateOrDestoryLinkList(int num, LLPP head, LLPP tail)
{
	if (*head == NULL && num != 0)//没有链表且长度非零
	{
		gets_s(a);
		LLP p1 = (LLP)malloc(sizeof(LL)),p2 = NULL;
		*head = p1;
		p1->prior = NULL;
		for (int i = 1; i <= num; i++)
		{
			if (i == num) *tail = p1;
			printf("请输入第%d个链表节点数据:\n", i);
			gets_s(p1->str);
			p2 = p1;
			p1 = (LLP)malloc(sizeof(LL));
			p2->next = p1;
			p1->prior = p2;
		}
		p2->next = NULL;
	}
	else if (*head != NULL)//有链表
	{
		LLP p1 = *head, p2 = *head;
		while (p1->next != NULL)
		{
			p1 = p1->next;
			free(p2);
			p2 = p1;
		}
		free(p1);
		*head = NULL, *tail = NULL;
		if (num != 0) CreateOrDestoryLinkList(num, head, tail);//非0的话销毁后重新创建链表
	}
}

void AddToHead(LLPP head)//插头
{
	gets_s(a);
	LLP p1 = (LLP)malloc(sizeof(LL));
	printf("请输入新头节点内容:\n");
	gets_s(p1->str);
	p1->next = *head;
	p1->prior = NULL;
	(*head)->prior = p1;
	*head = p1;
	printf("插入头节点完成\n");
}

void AddToTail(LLPP tail)//插尾
{
	gets_s(a);
	LLP p1 = (LLP)malloc(sizeof(LL));
	printf("请输入新尾节点内容:\n");
	gets_s(p1->str);
	(*tail)->next = p1;
	p1->prior = *tail;
	*tail = p1;
	p1->next = NULL;
	printf("插入尾节点完成\n");
}

void DeleteNode(LLPP head,LLPP tail)//删除节点
{
	int func;
	LLP p1 = *head, p2 = *head;
	int count = 0;
	while (1)
	{
		printf("请选择删除方式:\n1.查找对应内容并删除\n2.选择某一节点删除\n\n选择方式:");
		scanf("%d", &func);
		system("cls");
		if (func == 1 || func == 2) break;
	}
	gets_s(a);
	if (func == 1)//查找删除
	{
		char Find[100] = {};
		printf("请输入目标含有的内容:");
		gets_s(Find);
		while (p1 != NULL)
		{
			if (strstr(p1->str, Find) != NULL)//发现含有目标字符串的节点
			{
				if (p1 == *head && p1->next != NULL) *head = p1->next,(p1->next)->prior=NULL;//为头节点且有下一个节点
				else if (p1 == *head && p1->next == NULL) *head = NULL, * tail = NULL;//为头节点但没有下一个
				else
				{
					while (strstr(p1->str, Find) != NULL)//用于跳过连续一段符合的节点甚至跳到结束
					{ 
						p1 = p1->next;
						if (p1 == NULL) break;
					}
					if (p1 == NULL) { *tail = p2; p2->next = NULL; break; }//跳到结束
					else if (p1->next == NULL) { p2->next = p1; p1->prior = p2; *tail = p1; break; }//跳到最后一个
					else p2->next = p1,p1->prior=p2;//跳在最后一个前.正常连接
				}
			}
			p2 = p1;
			p1 = p1->next;
		}
		printf("所有含有该内容的节点已删除\n");
	}
	else//选择删除
	{
		printf("当前链表列表如下,请选择\n(选择 0 取消删除并返回)\n");
		while (p1 != NULL)
		{
			count++;//总计节点数
			printf("[%d]%s\n", count, p1->str);
			p1 = p1->next;
		}
		p1 = *head;
		int num;//选择节点序号
		while (1)
		{
			printf("请输入想要删除的节点序号:");
			scanf("%d", &num);
			if (num >= 0 && num <= count) break;
			else printf("该序号节点不存在,请重新输入:");
		}
		if (num == 0);
		else if (num == 1) *head = p1->next;
		else
		{
			for (int i = 1; i < num; i++)//从1开始,跳num-1次
			{
				p2 = p1;
				p1 = p1->next;
			}
			if (num == count) { *tail = p2; p2->next = NULL; }
			else p2->next = p1->next,(p1->next)->prior=p2;
		}
		printf("指定节点已删除\n");
	}
}

void DisplayLL(LLP head)
{
	LLP p1 = head;
	while (p1 != NULL)
	{
		printf("%s\n", p1->str);
		p1 = p1->next;
	}
}

void DisplayLL2(LLP tail)
{
	LLP p = tail;
	while (p != NULL)
	{
		printf("%s\n", p->str);
		p = p->prior;
	}
}

void CenterPoint(LLP head)
{
	LLP p1 = head, p2 = head;
	int count=1,x2=0;
	while (1)
	{
		p2 = p2->next;//跳一次,奇数中点
		if (p2 == NULL) break;
		p2 = p2->next;//跳两次,偶数中点
		if (p2 == NULL) {x2 = 1; break;}
		p1 = p1->next;
		count++;
	}
	if (x2) 
	{
		printf("该链表有偶数个节点,中点节点为:\n");
		printf("第%d个节点:%s\n", count, p1->str);
		printf("第%d个节点:%s\n", count+1, (p1->next)->str);
	}
	else
	{
		printf("该链表有奇数个节点,中点节点为:\n");
		printf("第%d个节点:%s\n", count, p1->str);
	}
}

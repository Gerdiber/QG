typedef struct StackNode {//链栈
	char data;//收集输入字符
	int power;//给定运算符号权重
	double num;//运算数字转换
	struct StackNode* next;
} SN, * SNP, ** SNPP;

void CreateLinkStack(SNPP head1,char inputsign,char *outputsign,int *outputnum)
{
	SNP p1 = (SNP)malloc(sizeof(SN));
	p1->power = 0;//权重默认是0 -> ( , )
	p1->data = inputsign;
	if (p1->data == '+' || p1->data == '-') p1->power = 1;// + ,- 权重为1
	if (p1->data == '*' || p1->data == '/') p1->power = 2;// * ,/ 权重为2
	if (*head1 != NULL)
	{
		p1->next = *head1;
		*head1 = p1;
	}
	else { *head1 = p1; p1->next = NULL; }
	if (p1->data == ')')//是右括号就找到左括号并让中间内容出栈
	{
		SNP p2 = p1;
		while (1)
		{
			p2 = p2->next;
			if (p2->data == '(')
			{
				p1 = p2->next;//找到左括号就让头指向左括号下一个
				*head1 = p1;
				free(p2);
				break;
			}
			else//括号里内容出栈
			{
				*outputsign = p2->data;
				outputsign++;
				*outputnum = (*outputnum) + 1;
			}
			free(p1);
			p1 = p2;
		}
	}
	else if (p1->data == '(');
	else if (p1->next!=NULL)//左右括号处理完就是运算符
	{
		if (p1->power <= (p1->next)->power)//刚入栈的权重小于原来的栈顶
		{
			SNP p2;
			while (1)
			{
				p2 = (p1->next)->next;
				*outputsign = (p1->next)->data;//出栈
				outputsign++;
				*outputnum = (*outputnum) + 1;
				free(p1->next);
				p1->next = p2;
				if (p2 == NULL || p2->data == '(' || p1->power > p2->power) break;
				//直到尾都没有大于的/遇到左括号/遇到权重大于的 就结束
			}
		}
	}
}

void ClearLinkStack(SNPP head, char* outputsign)//清空链栈剩余节点让其出栈
{
	SNP p1 = *head;
	while (p1 != NULL)
	{
		*outputsign = p1->data;
		outputsign++;
		p1 = p1->next;
	}

}

void DestoryLinkStack(SNPP head)//销毁链栈
{
	SNP p1 = *head, p2 = *head;
	while (p1->next != NULL)
	{
		p1 = p1->next;
		free(p2);
		p2 = p1;
	}
	free(p1);
	*head = NULL;
}

double Calculate(char str[])//获取转换来的后缀表达式并计算
{
	double result=0;
	SNP head=NULL;
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			SNP p1 = (SNP)malloc(sizeof(SN));
			p1->num = str[i] - '0';
			if (i) p1->next = head;
			head = p1;
		}//获取数字
		else
		{
			double num1 = (head->next)->num, num2 = head->num;
			if (str[i] == '+') result = num1 + num2;
			else if (str[i] == '-') result = num1 - num2;
			else if (str[i] == '*') result = num1 * num2;
			else if (str[i] == '/') result = num1 / num2;
			SNP p2 = head->next;
			p2->num = result;
			free(head);
			head = p2;
		}//运算
	}
	return result;
}

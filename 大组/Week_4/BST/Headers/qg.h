typedef struct Node//二叉树节点
{
	int data;
	struct Node* left, * right;
}Node,*NodeP,**NodePP;

typedef struct Link//栈与队操作
{
	int times;//记录入栈节点被访问次数,3次出栈(后序遍历)
	NodeP node;
	struct Link* next;
	struct Link* prior;
}Link,*LinkP;
LinkP head = NULL, tail = NULL;
void inStackorQueue(NodeP node)//入栈or入队
{
	if (node == NULL);
	else
	{
		LinkP p1 = (LinkP)malloc(sizeof(Link));
		p1->node = node, p1->next = NULL, p1->prior = NULL;
		if (head == NULL) head = p1, tail = p1;
		else
		{
			tail->next = p1;
			p1->prior = tail;
			tail = p1;
		}
	}
}
NodeP outStack()//出栈(返回出栈节点)
{
	NodeP a = tail->node;
	LinkP p1 = tail;
	tail = tail->prior;
	free(p1);
	if (tail == NULL) head = NULL;
	return a;
}
NodeP outQueue()//出队(返回出队节点)
{
	NodeP a = head->node;
	LinkP p1 = head;
	head = head->next;
	free(p1);
	if (head == NULL) tail = NULL;
	return a;
}

void bst_insert(NodePP root,int data)//二叉树数据插入
{
	NodeP p1 = (NodeP)malloc(sizeof(Node));
	p1->data = data, p1->left = NULL, p1->right = NULL;
	if (*root == NULL)//空二叉树
	{
		*root = p1;
		printf("数据插入成功\n");
	}
	else//非空二叉树
	{
		NodeP p2 = *root;//遍历二叉树与p1数据比对
		while (1)
		{
			if (p1->data == p2->data)//找到数据
			{
				printf("该数据已存在,无需插入\n");
				break;
			}
			else if (p1->data < p2->data)//小于进入左侧
			{
				if (p2->left == NULL)
				{
					p2->left = p1;
					printf("数据插入成功\n");
					break;
				}
				else p2 = p2->left;
			}
			else if (p1->data > p2->data)//大于进入右侧
			{
				if (p2->right == NULL)
				{
					p2->right = p1;
					printf("数据插入成功\n");
					break;
				}
				else p2 = p2->right;
			}
		}
	}
}

void bst_delete(NodePP root,int data)//二叉树数据删除
{
	NodeP p1 = *root;//p1从根节点开始
	NodeP p2 = p1;//记录p1的上一个节点
	int dir = 0;//记录p1方向   0为根节点   1为p2的左节点   2为p2的右节点
	while (1)
	{
		if (data == p1->data)//发现对应数据节点
		{
			if (p1->left == NULL && p1->right == NULL)//叶子节点
			{
				if (dir == 0) *root = NULL;
				else if (dir == 1) p2->left = NULL;
				else if (dir == 2) p2->right = NULL;
			}
			else if (p1->left == NULL)//右孩节点
			{
				if (dir == 0) *root = p1->right;
				else if (dir == 1) p2->left = p1->right;
				else if (dir == 2) p2->right = p1->right;
			}
			else if (p1->right == NULL)//左孩节点
			{
				if (dir == 0) *root = p1->left;
				else if (dir == 1) p2->left = p1->left;
				else if (dir == 2) p2->right = p1->left;
			}
			else//双孩节点
			{
				if ((p1->left)->right != NULL)//直接前驱存在
				{
					p2 = p1->left;
					NodeP p3 = (p1->left)->right;
					while (p3->right != NULL)
					{
						p2 = p3;
						p3 = p3->right;
					}
					int ex = p1->data;
					p1->data = p3->data;
					p3->data = ex;
					p1 = p3;
					p2->right = NULL;
				}
				else if ((p1->right)->left != NULL)//直接后继存在
				{
					p2 = p1->right;
					NodeP p3 = (p1->right)->left;
					while (p3->left != NULL)
					{
						p2 = p3;
						p3 = p3->left;
					}
					int ex = p1->data;
					p1->data = p3->data;
					p3->data = ex;
					p1 = p3;
					p2->left = NULL;
				}
				else//无直接前驱和直接后继
				{
					(p1->left)->right = p1->right;
					if (dir == 0) *root = p1->left;
					else if (dir == 1) p2->left = p1->left;
					else if (dir == 2) p2->right = p1->left;
				}
			}
			free(p1);
			printf("含有该数据的节点已删除\n");
			break;
		}
		else if (data < p1->data)//节点数据小于查找数据
		{
			if (p1->left == NULL)
			{
				printf("含有该数据的节点不存在\n");
				break;
			}
			else
			{
				p2 = p1;
				p1 = p1->left;
				dir = 1;
			}
		}
		else if (data > p1->data)//节点数据大于查找数据
		{
			if (p1->right == NULL)
			{
				printf("含有该数据的节点不存在\n");
				break;
			}
			else
			{
				p2 = p1;
				p1 = p1->right;
				dir = 2;
			}
		}
	}
}

void bst_search(NodeP root,int data)//二叉树数据删除
{
	NodeP p1 = root;
	while (1)
	{
		if (data == p1->data)
		{
			printf("查找到含有该数据的节点\n");
			break;
		}
		else if (data < p1->data)
		{
			if (p1->left == NULL)
			{
				printf("未查找到含有该数据的节点\n");
				break;
			}
			else p1 = p1->left;
		}
		else if (data > p1->data)
		{
			if (p1->right == NULL)
			{
				printf("未查找到含有该数据的节点\n");
				break;
			}
			else p1 = p1->right;
		}
	}
}

void bst_preorder(NodeP root)//先序遍历
{
	if (root == NULL);
	else
	{
		inStackorQueue(root);
		while (1)
		{
			NodeP p1 = outStack();
			printf("%d ", p1->data);
			inStackorQueue(p1->right);
			inStackorQueue(p1->left);
			if (tail == NULL) break;
		}
	}
}

void bst_preorderR(NodeP root)//先序遍历(递归)
{
	if (root == NULL);
	else
	{
		printf("%d ", root->data);
		bst_preorderR(root->left);
		bst_preorderR(root->right);
	}
}

void bst_inorder(NodeP root)//中序遍历
{
	if (root == NULL);
	else
	{
		NodeP p1 = root;
		while (1)
		{
			if (p1 != NULL)
			{
				inStackorQueue(p1);
				p1 = p1->left;
			}
			else
			{
				p1 = outStack();
				printf("%d ", p1->data);
				p1 = p1->right;
			}
			if (head == NULL && p1 == NULL) break;
		}
	}
}

void bst_inorderR(NodeP root)//中序遍历(递归)
{
	if (root == NULL);
	else
	{
		bst_inorderR(root->left);
		printf("%d ", root->data);
		bst_inorderR(root->right);
	}
}

void bst_postorder(NodeP root)//后序遍历
{
	if (root == NULL);
	else
	{
		NodeP p1 = root;
		while (1)
		{
			if (p1 != NULL)
			{
				inStackorQueue(p1);
				tail->times = 1;//第一次访问,左分支
				p1 = p1->left;
			}
			else//访问到空节点折返
			{
				if (tail->times == 1)//第一次折返,进入右分支
				{
					p1 = (tail->node)->right;
					tail->times = 2;//第二次访问,右分支
				}
				else//第二次折返,折返点出栈
				{
					p1 = outStack();//第三次访问,出栈
					printf("%d ", p1->data);
					p1 = NULL;//出栈后回到新的栈顶
				}
			}
			if (head == NULL && p1 == NULL) break;
		}
	}
}

void bst_postorderR(NodeP root)//后序遍历(递归)
{
	if (root == NULL);
	else
	{
		bst_postorderR(root->left);
		bst_postorderR(root->right);
		printf("%d ", root->data);
	}
}

void bst_levelorder(NodeP root)//层次遍历
{
	if (root == NULL);
	else
	{
		inStackorQueue(root);
		while (1)
		{
			NodeP p1 = outQueue();
			int a = p1->data;
			printf("%d ", a);
			inStackorQueue(p1->left);
			inStackorQueue(p1->right);
			if (head == NULL) break;
		}
	}
}

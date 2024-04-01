//插入排序
void InsertSort(int* a, int n)
{
	int ex;
	for (int i = 0; i < n; i++)//往前排序
	{
		for (int j = i; j > 0; j--)//往返插入
		{
			if (a[j] < a[j - 1])
			{
				ex = a[j];
				a[j] = a[j - 1];
				a[j - 1] = ex;
			}
		}
	}
}

//归并排序
void Merge(int* a, int* temp, int begin, int mid, int end)//排序两个有序数组
{
	int left_num = begin;
	int right_num = mid + 1;
	int all_num = begin;
	while ((left_num <= mid) && (right_num <= end))//把有序数组逐个元素排序
	{
		if (a[left_num] < a[right_num]) temp[all_num++] = a[left_num++];
		else temp[all_num++] = a[right_num++];
	}
	while (left_num <= mid) temp[all_num++] = a[left_num++];//把剩余的有序数组元素接入
	while (right_num <= end) temp[all_num++] = a[right_num++];
	for (int i = begin; i <= end; i++) a[i] = temp[i];
}
void MergeSort(int* a, int* temp, int begin, int end)//递归拆分数组并不断组成有序子数组
{
	if (begin < end)
	{
		int mid = (begin + end) / 2;//获取每个子数组的中间索引号
		MergeSort(a, temp, begin, mid);//拆分排序左部分
		MergeSort(a, temp, mid + 1, end);//拆分排序右部分
		Merge(a, temp, begin, mid, end);//再排序2个有序数组
	}
}

//快速排序
void QuickSort(int* a, int begin, int end)
{
	if (begin < end)
	{
		int middle = begin;//用于比较分区的中间值索引号
		int find = middle + 1;//中间值下一个开分
		int ex;//交换用变量
		for (int i = find; i <= end; i++)
		{
			if (a[i] < a[middle])//小于大于分两侧
			{
				ex = a[i];
				a[i] = a[find];
				a[find] = ex;
				find++;
			}
		}
		ex = a[middle];//再把中间值与小于最后一个交换
		a[middle] = a[find - 1];
		a[find - 1] = ex;
		middle = find - 1;
		QuickSort(a, begin, middle - 1);//中间值左侧进入递归继续分区
		QuickSort(a, middle + 1, end);//右侧同
	}
}

//计数排序
void CountSort(int* a, int size)
{
	int max = a[0];
	for (int i = 1; i < size; i++) max = a[i] > max ? a[i] : max;//寻最大值
	int* b = new int[max + 1];//存储数组元素出现次数
	for (int i = 0; i <= max; i++) b[i] = 0;
	int num = 0;
	for (int i = 0; i < size; i++)	b[a[i]] += 1;
	for (int i = 0; i <= max; i++)//有次数的元素打印对应次数次
	{
		if (b[i] == 0) continue;
		for (int j = 0; j < b[i]; j++) a[num++] = i;
	}
}

//基数排序
void RadixCountSort(int* a, int size)
{
	int* c = new int[size + 1];//转存位数排序后的数组用
	int max=a[0];
	for (int i = 1; i < size; i++) max = a[i] > max ? a[i] : max;//寻最大值
	for (int x=1;max!=0;max/=10,x*=10)//依据最大值位数决定循环排序次数
	{
		int b[10] = {};
		for (int i = 0; i < size; i++) b[a[i] / x % 10]++;//计数
		for (int i = 1; i < 10; i++) b[i] += b[i - 1];//累计
		for (int i = size - 1; i >= 0; i--)
		{
			c[b[a[i] / x % 10] - 1] = a[i];//转存
			b[a[i] / x % 10]--;
		}
		for (int i = 0; i < size; i++) a[i] = c[i];//赋值
	}
}

//颜色排序
void ColorSort(int* a, int size)
{
	int begin = 0, end = size - 1;
	int ex;
	for (int i = 0; i < size; i++)//遍历数组
	{
		if (a[i] == 0)//0则正常交换
		{
			ex = a[i];
			a[i] = a[begin];
			a[begin] = ex;
			begin++;
		}
		else if (a[i] == 2)//2则区分情况
		{
			if (a[end] == 2)//尾元素值也是2则遍历暂停,尾索引号往前 
			{
				i--, end--;
				continue;
			}
			ex = a[i];//非2进行交换
			a[i] = a[end];
			a[end] = ex;
			end--;
			if (a[i] == 0)//若是0则交换后暂停遍历重新把0交换到前面再遍历
			{
				i--;
				continue;
			}
		}
		if (end == i) break;//到尾结束
	}
}

//第k大/小数...
int GetKMax(int* a, int begin, int end, int k)
{
	QuickSort(a, begin, end);
	return a[end - k + 1];
}
int GetKMin(int* a, int begin, int end, int k)
{
	QuickSort(a, begin, end);
	return a[k-1];
}


//模拟部分排序情况并测试耗时
void mg(int bg, int mid, int ed)
{
	int a = 0, b = 1, c = 0;
	int x = (mid - bg) > (ed - mid - 1) ? mid - bg + 1 : ed - mid;
	for (int i = 0; i < x; i++)
	{
		a = b;
		c++;
	}
	for (int i = bg; i <= ed; i++)
	{
		a = b;
		c++;
	}
	for (int i = bg; i <= ed; i++) a = b;
}
void mgs(int bg, int ed)
{
	if (bg < ed)
	{
		mgs(bg, (bg + ed) / 2);
		mgs((bg + ed) / 2 + 1, ed);
		mg(bg, (bg + ed) / 2, ed);
	}
}
void qs(int bg, int ed)
{
	if (bg < ed)
	{
		int a = 0, b = 1, c = 0;
		for (int i = bg + 1; i < ed; i++)
		{
			c = b;
			b = a;
			a = c;
		}
		qs(bg, (bg + ed) / 2);
		qs((bg + ed) / 2 + 1, ed);
	}
}
void TimeCount(int data,int times)
{
	int a = 0, b = 1, c = 0;
	clock_t start1 = clock();
	for (int x = 0; x < times; x++)
	{
		for (int i = 0; i < data; i++)
		{
			for (int j = i; j > 0; j--)
			{
				int t = a;
				a = b;
				b = t;
			}
		}
	}
	clock_t over1 = clock() - start1;
	printf("插入排序:%dms\n", over1);

	clock_t start2 = clock();
	for (int x = 0; x < times; x++)
	{
		mgs(1, data);
	}
	clock_t over2 = clock() - start2;
	printf("归并排序:%dms\n", over2);

	clock_t start3 = clock();
	for (int x = 0; x < times; x++)
	{
		qs(1, data);
	}
	clock_t over3 = clock() - start3;
	printf("快速排序:%dms\n", over3);

	clock_t start4 = clock();
	for (int x = 0; x < times; x++)
	{
		for (int i = 0; i < data; i++) a = b;
		for (int i = 0; i < data; i++) a = b;
		for (int i = 0; i < data; i++) a = b;
		for (int i = 0; i < data; i++) a = b;
	}
	clock_t over4 = clock() - start4;
	printf("计数排序:%dms\n", over4);

	clock_t start5 = clock();
	for (int x = 0; x < times; x++)
	{
		for (int i = 0; i < data; i++) a = b;
		for (int i = 0; i < 5; i++)
		{
			for (int i = 0; i < data; i++) a = b;
			for (int i = 0; i < 10; i++) a = b;
			for (int i = 0; i < data; i++) { a = b; c++; }
			for (int i = 0; i < data; i++) a = b;
		}
	}
	clock_t over5 = clock() - start5;
	printf("基数排序:%dms\n", over5);
}

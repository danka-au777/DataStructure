#include "utility.h"				// 实用程序软件包
#include "tri_sparse_matrix.h"		// 稀疏矩阵的三元组顺序表

int main(void)
{
	
    try								// 用try封装可能出现异常的代码
	{
		const int n = 5;
		TriSparseMatrix<int> a(n, n);	// 定义一个n行n列稀疏矩阵
		int b[n][n] = {
			1,	0,	3,	0,	0, 
			4,	0,	6,	0,	0, 
			0,	0,	8,	9,	0, 
			0,	0,	0,	1,	12,
			1,	0,	0,	3,	1
		};
		int i, j, v;					// 工作变量	

		// 设置稀疏矩阵a的元素值
		for (i = 1; i <= n; i++)
		{	// 行
			for (j = 1; j <= n; j++)
			{	// 列	
				a.SetElem(i, j, b[i - 1][j - 1]);	// 设置元素值
			}
		}

		TriSparseMatrix<int> c(a);		// 复制构造函数
		c = a;							// 赋值运算符重载
		
		// 显示稀疏矩阵c
		for (i = 1; i <= c.GetRows(); i++)
		{	// 行
			for (j = 1; j <= c.GetCols(); j++)
			{	// 列
				c.GetElem(i, j, v);		// 求元素值
				cout << v << "\t";		// 显示元素值
			}
			cout << endl;
		}
	}
	catch (Error err)		// 捕捉并处理异常
	{
		err.Show();			// 显示异常信息
	}

	system("PAUSE");        // 调用库函数system()
	return 0;               // 返回值0, 返回操作系统
}



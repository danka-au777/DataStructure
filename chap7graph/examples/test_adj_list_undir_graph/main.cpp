#include "utility.h"					// 实用程序软件包
#include "adj_list_undir_graph.h"		// 邻接表无向图

int main(void)
{
    try									// 用try封装可能出现异常的代码
	{
		char vexs[] = {'A', 'B', 'C', 'D'};
		int m[4][4] = {
			{0, 1, 0, 1},
			{1, 0, 1, 1},
			{0, 1, 0, 1},
			{1, 1, 1, 0}
		};
		char e;
		int n = 4;

		AdjListUndirGraph<char> g(vexs, n);

		int u;							// 临时变量 
		for (u = 0; u < n; u++)
		{	// 生成邻接矩阵的行
			for (int v = 0; v < n; v++)
			{	// 生成邻接矩阵元素的值
				if (m[u][v] == 1) g.InsertEdge(u, v);
			}
		}

		cout << "原无向图:" << endl;
		Display(g);						// 显示图g
		cout << endl;
		system("PAUSE");				// 调用库函数system()

		AdjListUndirGraph<char> g1(g);	// 复制构造函数	
		cout << "复制构造图:" << endl;
		Display(g1);					// 显示图g1
		cout << endl;
		system("PAUSE");				// 调用库函数system()

		g1 = g;						// 赋值语句重载 
		cout << "赋值语句重载构造图:" << endl;
		Display(g1);					// 显示图g1
		cout << endl;
		system("PAUSE");				// 调用库函数system()

		g1.DeleteEdge(2, 3);			// 删除边<2, 3>
		cout << "g1.DeleteEdge(2, 3)执行后图为：" << endl;
		Display(g1);					// 显示图g1
		cout << endl;
		system("PAUSE");				// 调用库函数system()

		int v = 1;
		g1.GetElem(v, e);				// 取出顶点v的元素值
		cout << "顶点" << e << "的邻接点为:";
		for (u = g1.FirstAdjVex(v); u != -1; u = g1.NextAdjVex(v, u))
		{	// 显示v的邻接点信息
			g1.GetElem(u, e);			// 取出顶点u的元素值
			cout << e << " ";
		}
		cout << endl << endl;
	}
	catch (Error err)					// 捕捉并处理异常
	{
		err.Show();						// 显示异常信息
	}

	system("PAUSE");					// 调用库函数system()
	return 0;							// 返回值0, 返回操作系统
}


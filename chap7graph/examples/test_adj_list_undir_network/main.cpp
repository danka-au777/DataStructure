#include "utility.h"					// 实用程序软件包
#include "adj_list_undir_network.h"		// 邻接表无向网

int main(void)
{
    try									// 用try封装可能出现异常的代码
	{
		int infity = DEFAULT_INFINITY;
		char vexs[] = {'A', 'B', 'C', 'D'};
		int m[4][4] = {
			{infity, 2, 3, 4},
			{2, infity, 5, 6},
			{3, 5, infity, 7},
			{4, 6, 7, infity}
		};
		char e;
		int n = 4;

		AdjListUndirNetwork<char, int> net(vexs, n);

		int u;							// 临时变量 
		for (u = 0; u < n; u++)
		{	// 生成邻接矩阵的行
			for (int v = 0; v < n; v++)
			{	// 生成邻接矩阵元素的值
				if (m[u][v] != infity) net.InsertEdge(u, v, m[u][v]);
			}
		}

		cout << "原无向网:" << endl;
		Display(net);					// 显示网net
		cout << endl;
		system("PAUSE");				// 调用库函数system()

		AdjListUndirNetwork<char, int> net1(net);	// 复制构造函数	
		cout << "复制构造网:" << endl;
		Display(net1);					// 显示网net1
		cout << endl;
		system("PAUSE");				// 调用库函数system()

		net1 = net;						// 赋值语句重载 
		cout << "赋值语句重载构造网:" << endl;
		Display(net1);					// 显示网net1
		cout << endl;
		system("PAUSE");				// 调用库函数system()

		net1.DeleteEdge(2, 3);			// 删除边<2, 3>
		cout << "net1.DeleteEdge(2, 3)执行后网为：" << endl;
		Display(net1);					// 显示网net1
		cout << endl;
		system("PAUSE");				// 调用库函数system()

		net1.SetWeight(1,3, 88);		// 修改<1, 3>权为88
		cout << "net1.SetWeight(1,3, 88)执行后网为：" << endl;
		Display(net1);					// 显示网net1
		cout << endl;
		system("PAUSE");				// 调用库函数system()

		int v = 1;
		net1.GetElem(v, e);				// 取出顶点v的元素值
		cout << "顶点" << e << "的邻接点为:";
		for (u = net1.FirstAdjVex(v); u != -1; u = net1.NextAdjVex(v, u))
		{	// 显示v的邻接点信息
			net1.GetElem(u, e);			// 取出顶点u的元素值
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


#include "utility.h"	// 这用程序软件包
#include "sq_queue.h"	// 循环队列类

int  main(void)
{
	char c = '0';
    SqQueue<double> qa,qb;
    double x;

    while (c != '6')
	{
        cout << endl << "1. 生成队列.";
        cout << endl << "2. 显示队列.";
        cout << endl << "3. 入队列.";
        cout << endl << "4. 出队列.";
        cout << endl << "5. 取队列头.";
		cout << endl << "6. 退出";
		cout << endl << "选择功能(1~6):";
		cin >> c;
		switch (c) 
		{
			case '1':
				cout << endl << "输入e(e = 0时退出)";
				while (x != 0)
				{
					cin >> x;
					if (x != 0)
						qa.InQueue(x);
				}
				break;
	       case '2':
			    qb = qa;
				cout << endl;
			    qb.Traverse(Write<double>);
				break;
		   case '3':
			    cout << endl << "输入元素值:";
			    cin >> x;
			    qa.InQueue(x);
			    break;
           case '4':
			    qa.OutQueue(x);
			    cout << endl << "队头元素值为 " << x << " ." << endl;
			    break;
           case '5':
			    qa.GetHead(x);
			    cout << endl << "队头元素值为 " << x << " ." << endl;
			    break;
		   case '6':;
		}
	}

	return 0;
}



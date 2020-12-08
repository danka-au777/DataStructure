#include "utility.h"	// 实用程序软件包
#include "polynomial.h"	// 多项式类
#include "ass.h"		// 辅助函数

int main(void)
{
	char c = '0';
    Polynomial fa, fb, fc;
    PolyItem it;

    while (c != '6')
	{
        cout << endl << "1. 生成多项式.";
        cout << endl << "2. 显示多项式.";
        cout << endl << "3. 多项式加法.";
        cout << endl << "4. 多项式减法.";
        cout << endl << "5. 多项式乘法.";
		cout << endl << "6. 退出";
		cout << endl << "选择功能(1~6):";
		cin >> c;
		switch (c) 
		{
			case '1':
				cout << endl << "输入(coef, expn)(coef = -1时退出):" << endl;
				cin >> it.coef >> it.expn;
				while (it.expn != -1)
				{
					fa.InsItem(it);
					cin >> it.coef >> it.expn;
				}
				break;
			case '2':
			    fb = fa;
			    fa.Display();
				break;
			case '3':

				// 输入fa
				fa.IsZero();		// 将fa设置为0
				cout << endl << "输入fa的项(coef, expn)(e = -1时退出):" << endl;
				cin >> it.coef >> it.expn;
				while (it.expn != -1)
				{
					fa.InsItem(it);
					cin >> it.coef >> it.expn;
				}
			    
				// 输入fb
				fb.IsZero();		// 将fb设置为0
				cout << endl << "输入fb的项(coef, expn)(e = -1时退出):" << endl;
				cin >> it.coef >> it.expn;
				while (it.expn != -1)
				{
					fb.InsItem(it);
					cin >> it.coef >> it.expn;
				}
			    
				fc = fa + fb;

			    cout << "fa:" << endl;			// 显示fa
				fa.Display();
			    cout << endl;			

			    cout << "fb:" << endl;			// 显示fa
				fb.Display();
			    cout << endl;			

			    cout << "fa + fb:" << endl;		// 显示fc = fa + fb
				fc.Display();
			    cout << endl;			
				break;
			case '4':
				// 输入fa
				fa.IsZero();		// 将fa设置为0
				cout << endl << "输入fa的项(coef, expn)(e = -1时退出):" << endl;
				cin >> it.coef >> it.expn;
				while (it.expn != -1)
				{
					fa.InsItem(it);
					cin >> it.coef >> it.expn;
				}
			    
				// 输入fb
				fb.IsZero();		// 将fb设置为0
				cout << endl << "输入fb的项(coef, expn)(e = -1时退出):" << endl;
				cin >> it.coef >> it.expn;
				while (it.expn != -1)
				{
					fb.InsItem(it);
					cin >> it.coef >> it.expn;
				}
			    
				fc = fa - fb;

			    cout << "fa:" << endl;			// 显示fa
				fa.Display();
			    cout << endl;			

			    cout << "fb:" << endl;			// 显示fa
				fb.Display();
			    cout << endl;			

			    cout << "fa - fb:" << endl;		// 显示fc = fa - fb
				fc.Display();
			    cout << endl;			
			    break;
			case '5':
				// 输入fa
				fa.IsZero();		// 将fa设置为0
				cout << endl << "输入fa的项(coef, expn)(e = -1时退出):" << endl;
				cin >> it.coef >> it.expn;
				while (it.expn != -1)
				{
					fa.InsItem(it);
					cin >> it.coef >> it.expn;
				}
			    
				// 输入fb
				fb.IsZero();		// 将fb设置为0
				cout << endl << "输入fb的项(coef, expn)(e = -1时退出):" << endl;
				cin >> it.coef >> it.expn;
				while (it.expn != -1)
				{
					fb.InsItem(it);
					cin >> it.coef >> it.expn;
				}
			    
				fc = fa * fb;

			    cout << "fa:" << endl;			// 显示fa
				fa.Display();
			    cout << endl;			

			    cout << "fb:" << endl;			// 显示fa
				fb.Display();
			    cout << endl;			

			    cout << "fa * fb:" << endl;		// 显示fc = fa * fb
				fc.Display();
			    cout << endl;			
			    break;
		}
	}

	system("PAUSE");				// 调用库函数system()
	return 0;						// 返回值0, 返回操作系统
}

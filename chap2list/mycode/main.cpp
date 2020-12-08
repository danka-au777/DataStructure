#include "list.h"
using namespace std;
int main(){
    LinkList<int> la;
    char c='0';
    int e;
    int position;

     while (c != '7')
	{
        cout << endl << "1. 生成线性表.";
        cout << endl << "2. 显示线性表.";
        cout << endl << "3. 检索元素.";
        cout << endl << "4. 设置元素值.";
        cout << endl << "5. 删除元素.";
        cout << endl << "6. 插入元素.";
		cout << endl << "7. 退出";
		cout << endl << "选择功能(1~7):";
		cin >> c;
		switch (c) 
		{
			case '1':
				cout << endl << "输入e(e = 0时退出):";
				cin >> e;
				while (e != 0)
				{
					la.Insert(la.Length() + 1, e);
					cin >> e;
				}
				break;
			case '2':
                for(int i=1;i<la.Length()+1;i++){
                    e=la.GetElem(i);
                    cout<<e<<" ";
                }
                cout<<""<<endl;
				break;
			case '3':
			    cout << endl << "输入元素位置:";
			    cin >> position;
			    e=la.GetElem(position);
				cout << "元素:" << e << endl;
			    break;
			case '4':
			    cout << endl << "输入位置:";
			    cin >> position;
			    cout << endl << "输入元素值:";
			    cin >> e;
				la.SetElem(position, e);
			    break;
			case '5':
			    cout << endl << "输入位置:";
			    cin >> position;
			    e=la.Delete(position);
				cout << "被删除元素值:" << e << endl;
			    break;
			case '6':
			    cout << endl << "输入位置:";
			    cin >> position;
			    cout << endl << "输入元素值:";
			    cin >> e;
			    la.Insert(position, e); 
			    break;
		}
	}

    return 0;
}
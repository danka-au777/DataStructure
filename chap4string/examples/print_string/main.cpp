#include "utility.h"	// 实用程序软件包
#include "string.h"		// 串类

// 文件路径名:e4_1\main.cpp 

int main(void)
{
	String str;
	str = "some string.";
	const char *newStr = str.CStr();

	cout << newStr << endl;

	system("PAUSE");        // 调用库函数system()
	return 0;               // 返回值0, 返回操作系统
}
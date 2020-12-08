#ifndef __UTILITY_H__				// ���û�ж���__UTILITY_H__
#define __UTILITY_H__				// ��ô����__UTILITY_H__

// ʵ�ó���������

#ifdef _MSC_VER						// ��ʾ��VC 
#if _MSC_VER == 1200				// ��ʾVC6.0

// ��׼��ͷ�ļ�
#include <string.h>					// ��׼���Ͳ���
#include <iostream.h>				// ��׼������
#include <limits.h>					// ����
#include <math.h>					// ��ѧ����
#include <fstream.h>				// �ļ��������
#include <ctype.h>				 	// �ַ�����
#include <time.h>				 	// ���ں�ʱ�亯��
#include <stdlib.h>					// ��׼��
#include <stdio.h>					// ��׼�������
#include <iomanip.h>				// �����������ʽ����	
#include <stdarg.h> 				// ֧�ֱ䳤��������	
#include <assert.h>					// ֧�ֶ���

#else								// �����汾��VC++

// ANSI C++��׼��ͷ�ļ�
#include <string>					// ��׼���Ͳ���
#include <iostream>					// ��׼������
#include <limits>					// ����
#include <cmath>					// ��ѧ����
#include <fstream>					// �ļ��������
#include <cctype>					// �ַ�����
#include <ctime>       				// ���ں�ʱ�亯��
#include <cstdlib>					// ��׼��
#include <cstdio>       			// ��׼�������
#include <iomanip>					// �����������ʽ����	
#include <cstdarg> 					// ֧�ֱ䳤��������	
#include <cassert>					// ֧�ֶ���
using namespace std;				// ��׼������������ռ�std��

#endif	// _MSC_VER == 1200
#else								// ��VC 

// ANSI C++��׼��ͷ�ļ�
#include <Cstring>					// ��׼������
#include <iostream>					// ��׼������
#include <limits>					// ����
#include <cmath>					// ���ݺ���
#include <fstream>					// �ļ��������
#include <cctype>					// �ַ�����
#include <ctime>       				// ���ں�ʱ�亯��
#include <cstdlib>					// ��׼��
#include <cstdio>       			// ��׼�������
#include <iomanip>					// �����������ʽ����	
#include <cstdarg> 					// ֧�ֱ䳤��������	
#include <cassert>					// ֧�ֶ���
using namespace std;				// ��׼������������ռ�std��

#endif	// _MSC_VER



// �Զ�������
enum StatusCode {SUCCESS, FAIL, UNDER_FLOW, OVER_FLOW,RANGE_ERROR, DUPLICATE_ERROR,
	NOT_PRESENT, ENTRY_INSERTED, ENTRY_FOUND, VISITED, UNVISITED};

// �궨��
#define DEFAULT_SIZE 1000			// ȱʡԪ�ظ���
#define DEFAULT_INFINITY 1000000	// ȱʡ�����


// ʵ�ú���(ģ��)����
static char GetChar(istream &inStream = cin); // ��������inStream�������ո��Ʊ�����ȡһ�ַ�
static bool UserSaysYes();		// ���û��϶��ش�(yes)ʱ, ����true, �û��񶨻ش�(no)ʱ,����false
static void SetRandSeed();		// ���õ�ǰʱ��Ϊ���������
static int GetRand(int n);		// ����0 ~ n-1֮��������
static int GetRand();			// ���������
static int GetPoissionRand(double expectValue);// ��������ֵΪexpectValue��������� 
template <class ElemType >
void Swap(ElemType &e1, ElemType &e2);	// ����e1, e2ֵ֮
template<class ElemType>
void Display(ElemType elem[], int n);	// ��ʾ����elem�ĸ�����Ԫ��ֵ
template <class ElemType>
void Write(const ElemType &e);			// ��ʾ����Ԫ��

// ʵ����
class Timer;			// ��ʱ����Timer
class Error;			// ͨ���쳣��

static char GetChar(istream &inStream)
// �����������������inStream�������ո��Ʊ�����ȡһ�ַ�
{
	char ch;								// ��ʱ����
	while ((ch = (inStream).peek()) != EOF	// �ļ�������(peek()�������������н���1
											// �ַ�,���ĵ�ǰλ�ò���)
		&& ((ch = (inStream).get()) == ' '	// �ո�(get()�������������н���1�ַ�,��
											// �ĵ�ǰλ�������1��λ��)
		|| ch == '\t'));					// �Ʊ���
	
	return ch;								// �����ַ�
}

static bool UserSaysYes()
// �������: ���û��϶��ش�(yes)ʱ, ����true, �û��񶨻ش�(no)ʱ,����false
{
	char ch;							// �û��ش��ַ�
	bool initialResponse = true;		// ��ʼ�ش�

	do
	{	// ѭ��ֱ���û�����ǡ���Ļش�Ϊֹ
		if (initialResponse)
		{	// ��ʼ�ش�
			cout << "(y, n)?"; 
		}
		else
		{	// �ǳ�ʼ�ش�
			cout << "��y��n�ش�:";
		}
		
		while ((ch = GetChar()) == '\n');	// �����ո�,�Ʊ��������з���ȡһ�ַ�
		initialResponse = false;
	} while (ch != 'y' && ch != 'Y' && ch != 'n' && ch != 'N');
	while (GetChar() != '\n');		// ������ǰ�к�����ַ�
	
	if (ch == 'y' || ch == 'Y') return true;
	else return false;
}

// ��ʱ����Timer
class Timer
{
private:
// ���ݳ�Ա
	clock_t startTime;

public:
//  ��������
	Timer() { startTime = clock(); }			// ���캯��
	~Timer() {};								// ��������	
	double ElapsedTime()						// �����ѹ���ʱ��
	{
		clock_t endTime = clock();				// ����ʱ��
		return (double)(endTime - startTime) / (double)CLK_TCK;	
			// ���ش�Timer�������������һ�ε���reset()����ʹ�õ�CPUʱ��
	}
	void Reset() { startTime = clock(); }		// ���ÿ�ʼʱ��

};

#define MAX_ERROR_MESSAGE_LEN 100

// ͨ���쳣��                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                    
class Error
{
private:
// ���ݳ�Ա
	char message[MAX_ERROR_MESSAGE_LEN];// �쳣��Ϣ

public:
//  ��������
	Error(char mes[] = "һ�����쳣!")	// ���캯�� 
	{
		strcpy(message, mes);			// �����쳣��Ϣ
	}
	~Error(void) {};					// ��������	
	void Show() const					// ��ʾ�쳣��Ϣ
	{
		cout << message << endl;		// ��ʾ�쳣��Ϣ	
	}
};

static void SetRandSeed()
// ������������õ�ǰʱ��Ϊ���������
{ 
	srand((unsigned)time(NULL)); 
}

static int GetRand(int n)
// �������������0 ~ n-1֮��������
{ 
	return rand() % (n); 
}

static int GetRand()
// ������������������
{ 
	return rand(); 
}

static int GetPoissionRand(double expectValue)
// �����������������ֵΪexpectValue��������� 
{
	double x = rand() / (double)(RAND_MAX + 1);	// x���ȷֲ���[0, 1)
	int k = 0;
	double p = exp(-expectValue);			// pkΪ���ɷֲ�ֵ
	double s = 0;							// sk�������p0+p1+...+pk-1

	while (s <= x)
	{	// ��sk <= xʱѭ��, ѭ��������sk-1 <= x < sk
		s += p;								// ���
		k++;
		p = p * expectValue / k;			// ����һ��pk
	}
	return k - 1;							// k-1��ֵ������ϣֵΪexpectValue�Ĳ��ɷֲ�
}

template <class ElemType >
void Swap(ElemType &e1, ElemType &e2)
// �������: ����e1, e2ֵ֮
{
	ElemType temp;		// ��ʱ����
	// ѭ����ֵʵ�ֽ���e1, e2
	temp = e1;	e1 = e2;  e2 = temp;
}

template<class ElemType>
void Display(ElemType elem[], int n)
// �������: ��ʾ����elem�ĸ�����Ԫ��ֵ
{
	for (int i = 0; i < n; i++)
	{	// ��ʾ����elem
		cout << elem[i] << "  ";
	}
	cout << endl; 
}

template <class ElemType>
void Write(const ElemType &e)
// �������: ��ʾ����Ԫ��
{
    cout << e << "  ";
}

#endif

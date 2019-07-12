#include <iostream>
#include <stdarg.h>
#include <string>
using namespace std;

void Euler_linear_sieve(int size) {
	int Prime[10000] = { 0 };
	bool Number[10000] = { false };
	int count = 0;
	for (int i = 2; i <= size; i++) {
		if (!Number[i]) {
			Prime[count++] = i;
		}
		for (int j = 0;j<count,Prime[j]*i <= size; j++) {
			Number[i*Prime[j]] = true;
			if (i%Prime[j] == 0)break;
		}
	}
}

int add(int totalnum...)// totalnum指定了参数的个数,...表示参数不定, 为定义此类函数必需
{ 
	va_list intlist;// 定义参数表 intlist
	va_start(intlist, totalnum);// 指定开始参数为totalnum
	cout << totalnum << endl;
	int totaladd = 0;
	for (int i = 0; i < totalnum; i++)
	{
		totaladd += va_arg(intlist, int);// 取出参数类型为int的参数 你说的fmt是参数的类型如float等
	}
	va_end(intlist);// 参数取完
	return totaladd;
}

#define changename(str) str##name
void main(int argc, char* argv[])
{
	string changename(test) = "hello";
	cout <<testname<< endl;
}

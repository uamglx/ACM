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

int add(int totalnum...)// totalnumָ���˲����ĸ���,...��ʾ��������, Ϊ������ຯ������
{ 
	va_list intlist;// ��������� intlist
	va_start(intlist, totalnum);// ָ����ʼ����Ϊtotalnum
	cout << totalnum << endl;
	int totaladd = 0;
	for (int i = 0; i < totalnum; i++)
	{
		totaladd += va_arg(intlist, int);// ȡ����������Ϊint�Ĳ��� ��˵��fmt�ǲ�����������float��
	}
	va_end(intlist);// ����ȡ��
	return totaladd;
}

#define changename(str) str##name
void main(int argc, char* argv[])
{
	string changename(test) = "hello";
	cout <<testname<< endl;
}

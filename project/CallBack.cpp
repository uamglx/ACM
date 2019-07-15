#include <iostream>

typedef double(*CallbackFunction)(double a, double b); // �ص�����ָ��


void CallCallbackFunction(CallbackFunction p_Function) // ���ص�����
{
	CallbackFunction tempCallFunction = NULL;
	tempCallFunction = p_Function;

	double sum = tempCallFunction(1, 3);
	std::cout << "CallbackFunction �Ļص����=" << sum << std::endl;
}

double Add(double a, double b) // �ص�����
{
	return a + b;
}

int main()
{
	CallCallbackFunction(Add);
	getchar();
	return 0;
}

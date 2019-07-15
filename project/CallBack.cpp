#include <iostream>

typedef double(*CallbackFunction)(double a, double b); // 回调函数指针


void CallCallbackFunction(CallbackFunction p_Function) // 调回调函数
{
	CallbackFunction tempCallFunction = NULL;
	tempCallFunction = p_Function;

	double sum = tempCallFunction(1, 3);
	std::cout << "CallbackFunction 的回调结果=" << sum << std::endl;
}

double Add(double a, double b) // 回调函数
{
	return a + b;
}

int main()
{
	CallCallbackFunction(Add);
	getchar();
	return 0;
}

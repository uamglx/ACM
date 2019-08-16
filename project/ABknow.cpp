#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;


// 思路 A不知B不知 得到 A知条件 有多种组合，但是组合最终可以由多个乘积不能分解的组合和一个乘积可以分解的组合组成
// B知条件，将B的几种组合使用A的方式判断，只有一个成立时，B知
// 需要注意 A先说不知，所以需要先进行A知不知的判断
// 代码为数字可以相同，如果数字不同，将j = i和改为i+1 并且将j*j<=tprc改为<tprc即可

bool judgeA(int a, int b) {
	queue<int>A;
	int sum = a + b;
	for (int i = 1; i <= 20; i++) {
		if (i > sum - 1)break;
		for (int j = i; j <= 20; j++) {
			if (i + j > sum)break;
			if ((i + j) == sum) {
				A.push(i);
			}
		}
	}
	int t = A.size();
	if (t < 2)return 0;
	while (t--) {
		int i = A.front();
		A.pop();
		int tprc = i * (sum - i);
		int count = 0;
		for (int j = 1; j*j <= tprc; j++) {
			if (tprc%j == 0 && tprc / j <= 20) {
				count++;
			}
		}
		if (count > 1)A.push(i);
	}
	if (A.size() != 1)return 0;
	return 1;
}

bool judgeB(int a,int b) {

	queue<int>B;

	int sum = a + b;
	int prc = a * b;

	for (int i = 1; i <= 20; i++) {
		if (i > sum - 2)break;
		for (int j = i; j <= 20; j++) {
			if (i*j > prc)break;
			if ((i * j) == prc) {
				B.push(i);
			}
		}
	}

	int t = B.size();
	if (t < 2)return 0;
	int count = 0;
	while (t--) {
		int i = B.front();
		B.pop();
		if (judgeA(i, prc / i)) {
			count++;
		}
	}
	if (count != 1)return 0;

	return 1;
}

int main(){
	queue<int>A;
	queue<int>B;
	for (int i = 1; i <= 20; i++) {
		for (int j = i; j <= 20; j++) {
			if (judgeA(i,j)&& judgeB(i, j)) {
				A.push(i);
				B.push(j);
			}
		}
	}
	while (!A.empty()) {
		cout << A.front() << " " << B.front() << endl;
		A.pop();
		B.pop();
	}
	getchar();
}
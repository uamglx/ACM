#include <iostream>
using namespace std;
int num[11] = { 0 };
int dp[11][11] = { 0 };


int dfs(int pos, int pn, int lmt)
{
	if (pos == 0)return pn;
	if (dp[pos][pn] && !lmt)return dp[pos][pn];
	int top = lmt ? num[pos] : 9;
	int ans = 0;
	int tn = 0;
	for (int i = 0; i <= top; i++)
	{
		if (i == 1)tn = pn + 1;
		else tn = pn;
		ans += dfs(pos - 1, tn, lmt && (i == top));
	}
	if (!lmt)dp[pos][pn] = ans;
	return ans;
}

int solve(int n)
{
	memset(dp, 0, sizeof(int));
	int k = 0;
	while (n) {
		num[++k] = n % 10;
		n = n / 10;
	}
	int ans = dfs(k, 0, 1); 
	return ans;
}

int main()
{
	int n;
	cin >> n;
	int ans = 0;
	cout << solve(n) - solve(0) << endl;
	return 0;
}
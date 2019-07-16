class Solution {
public:
	vector<int> FindNumbersWithSum(vector<int> num, int s) {
		vector<int> ans;
		int first = 0, last = num.size() - 1;
		while (first < last) {
			if (num[first] + num[last] > s)last--;
			else if (num[first] + num[last] < s)first++;
			else break;
		}
		if (first < last) {
			ans.push_back(num[first]);
			ans.push_back(num[last]);
		}
		return ans;
	}
};
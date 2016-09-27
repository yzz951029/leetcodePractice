#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int>> ans;
		sort(candidates.begin(), candidates.end());
		vector<int> a;
		for (int i = 0; i<candidates.size(); i++)
		{
			search(ans, candidates, a, target, i, 0);
			a.clear();
		}
		return ans;
	}

	bool search(vector<vector<int>> &ans, vector<int> &can, vector<int> store, int target, int index, int sum)
	{
		if (sum + can[index] == target)
		{
			store.push_back(can[index]);
			ans.push_back(store);
			return true;
		}
		else if (sum + can[index]<target)
		{
			for (int i = 0; i + index<can.size(); i++)
			{
				store.push_back(can[index]);
				if (!search(ans, can, store, target, index + i, sum + can[index]))
					store.pop_back();
			}
		}
		else
			return false;
		return false;
	}
};

int main()
{
	vector<int> a{ 2,4,8 };
	Solution s;
	vector<vector<int>> b(s.combinationSum(a, 8));
}
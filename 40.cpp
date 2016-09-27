#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		sort(candidates.begin(), candidates.end());
		vector<vector<int>> answer;
		vector<int> record;
		search(candidates, target, record, answer, 0, 0);
		return answer;
	}

	void search(vector<int> &candidates, int target, vector<int> record, vector<vector<int>> &answer, int index, int sum)
	{
		int newSum = sum + candidates[index];
		if (newSum == target)
		{
			record.push_back(candidates[index]);
			answer.push_back(record);
			return;
		}
		else if (newSum>target)
		{
			return;
		}
		else
		{
			for (int i = index + 1; i<candidates.size(); i++)
			{
				record.push_back(candidates[index]);
				search(candidates, target, record, answer, i, newSum);
				record.pop_back();
			}
		}
	}
};


int main()
{
	vector<int> cat{ 1, 1, 2, 5, 6, 7, 10 };
	Solution s;
	s.combinationSum2(cat, 8);
}
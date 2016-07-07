#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		int answer = INT_MAX;
		sort(nums.begin(), nums.end());
		int aI = 0;
		int aJ = 0;
		int aK = 0;
		for (int k = 0; k < nums.size() - 2; k++)
		{
			int i = k + 1;
			int j = nums.size() - 1;
			while (i<j)
			{
				if (abs(nums[i] + nums[j] + nums[k] - target)<answer)
				{
					aI = i;
					aJ = j;
					aK = k;
					answer = abs(nums[i] + nums[j] + nums[k] - target);
				}
				if (nums[i] + nums[j] + nums[k] - target < 0)
					i++;
				else if (nums[i] + nums[j] + nums[k] - target > 0)
					j--;
				else
					return target;
			}
		}
		return nums[aI] + nums[aJ] + nums[aK];
	}
	int abs(int x)
	{
		return x > 0 ? x : -x;
	}
};
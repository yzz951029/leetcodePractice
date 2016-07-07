#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		sort(nums.begin(),nums.end());
		vector<vector<int>> answer;
		int k = 0;
		vector<int>::size_type size = nums.size();
		size = size - 1;
		for (; k < (int)nums.size() - 2; )//这里遇到一个奇怪的bug，写成k<nums,size()-1就会无限循环。发现返回的size_type是无符号整型，会把int转换成size_type
		{	
			bool flag = false;
			int i = k + 1;
			int j = nums.size() - 1;
			while (i < j)
			{
				if (nums[i] + nums[j] + nums[k] > 0)
				{
					do
					{
						j--;
					} while (nums[j + 1] == nums[j]);
				}
				else if (nums[i] + nums[j] + nums[k] == 0)
				{
					vector<int> a{ nums[i], nums[k], nums[j] };
					answer.push_back(a);
					flag = true;
					do
					{
						i++;
					} while (nums[i - 1] == nums[i]);
					do
					{
						j--;
					} while (nums[j + 1] == nums[j]);
				}
				else
				{
					do
					{
						i++;
					} while (nums[i - 1] == nums[i]);
				}
					//i++;
			}
			k++;
			if (flag)
			{
				while (nums[k - 1] == nums[k]&& k<nums.size() - 2)
					k++;
			}
		}
		return answer;
	}
};

int main()
{
	Solution s;
	vector<int> a{-2,0,0, 2, 2};
	cout << a.size() << endl;
	vector<vector<int>> b = s.threeSum(a);
	for (int i = 0; i < b.size(); i++)
	{
		for (int j = 0; j < b[i].size(); j++)
		{
			cout << b[i][j] << " ";
		}
		cout << endl;
	}
	system("Pause");
}
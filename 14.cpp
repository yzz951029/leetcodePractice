#include<string>
using namespace std;

class Solution {
public:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.size() == 0)
			return "";
		string prefix = strs[0];
		for (int i = 0; i < strs.size(); i++)
		{
			if (strs[i].size()<prefix.size())
				prefix = strs[i];
		}
		int size = prefix.size();
		int j = size - 1;
		while (j >= 0)
		{
			for (int i = 0; i < strs.size(); i++)
			{
				if (strs[i][j] != prefix[j])
				{
					size = j;
					break;
				}
			}
			j--;
		}
		return prefix.substr(0, size);
	}
};
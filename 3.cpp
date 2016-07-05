#include<iostream>
#include<string>
using namespace std;


class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		int hash[256];
		int maxlen = 0;
		int maxindex = 0;
		int m = 0;
		for (int i = 0; i < s.size(); i++)
		{
			for (int j = 0; j < 256; j++)
				hash[j] = 0;
			for (m = i; m < s.size(); m++)
			{
				if (hash[s[m]] == 1)
					break;
				hash[s[m]] = 1;
			}
			if (m - i>maxlen)
			{
				maxlen = m - i;
				maxindex = i;
			}
		}
		for (int i = maxindex; i < maxindex + maxlen; i++)
		{
			cout << s[i];
		}
		return 0;
	}
};


int main()
{
	Solution s;
	string a = "abcabcbb";
	s.lengthOfLongestSubstring(a);
	system("Pause");
}

#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	string longestPalindrome(string s) {
		int size = s.size();
		int maxlen = 1;
		int index = 0;
		bool flag = 0;
		for (int i = 0; i < size; i++)
		{
			int start = 0;
			int len = singleCentreExpand(s, i,start);
			if (len>maxlen)
			{
				maxlen = len;
				index = start;
			}
		}
		for (int i = 0; i < size; i++)
		{
			int start = 0;
			int len = doubleCentreExpand(s, i,start);
			if (len>maxlen)
			{
				maxlen = len;
				index = start;
				flag = 1;
			}
		}
		return s.substr(index, maxlen);
	}
	int singleCentreExpand(string s, int index,int &start)
	{
		int i = index, j = index;
		int size = s.size();
		int len = -1;
		while (i >= 0 && j < size&&s[i] == s[j])
		{
			i--;
			j++;
			len += 2;
		}
		start = i + 1;
		return len;
	}
	int doubleCentreExpand(string s, int index,int & start)
	{
		int i = index, j = index + 1;
		int len = 0;
		while (i >= 0 && j < s.size() && s[i] == s[j])
		{
			i--;
			j++;
			len += 2;
		}
		start = i + 1;
		return len;
	}
};

int main()
{
	Solution s;;
	cout << s.longestPalindrome("");
	system("Pause");
}
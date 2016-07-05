#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	string longestPalindrome(string s) {
		int **p;//二位数组p记录i到j是否为回文串
		int size = s.size();
		int maxlen = 0;
		int index = 0;
		p = new int*[size];
		for (int i = 0; i < size; i++)
		{
			p[i] = new int[size];
		}
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
				p[i][j] = 0;
		}
		for (int i = 0; i < size; i++)//初始换数组
		{
			p[i][i] = 1;
			if (i != size - 1 && s[i] == s[i + 1])
				p[i][i + 1] = 1;
		}
		for (int i = 3; i <= size; i++)//i代表长度
		{
			for (int j = 0; i + j <= size; j++)//j代表起始位置
			{
				if (s[j] == s[j + i - 1] && p[j + 1][j + i - 2] == 1)
				{
					p[j][j + i - 1] = 1;
				}
			}
		}
		for (int i = 0; i < size; i++)
		{
			for (int j = i; j < size; j++)
			{
				if (p[i][j] == 1)
				{
					if (j - i + 1>maxlen)
					{
						maxlen = j - i + 1;
						index = i;
					}
				}
			}
		}
		return s.substr(index, maxlen);
	}
};

int main()
{
	Solution s;
	cout << s.longestPalindrome("");
	system("Pause");
}
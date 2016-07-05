#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	string convert(string s, int numRows) {
		if (numRows == 1)
			return s;
		int n = 2 * numRows - 2;
		int index = 0;
		string *p = new string[numRows];
		for (int i = 0; i < numRows; i++)
		{
			p[i] = "";
		}
		while (index != s.size())
		{
			if (index%n < numRows)
				p[index%n] += s[index];
			else
				p[n - index%n] += s[index];
			index++;
		}
		string answer("");
		for (int i = 0; i < numRows; i++)
		{
			answer += p[i];
		}
		return answer;
	}
};

int main()
{
	Solution s;
	cout<<s.convert("A", 1);
	system("Pause");
}
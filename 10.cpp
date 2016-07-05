#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
	bool isMatch(string s, string p) {
		return match(s, p, 0, 0);
	}
	bool match(string s, string p, int sPtr, int pPtr)
	{
		int sSize = s.size();
		int pSize = p.size();
		if (sSize == sPtr)
		{
			if (pPtr == pSize)
				return true;
			else
			{
				while (pPtr < pSize)
				{
					if (p[pPtr + 1] != '*')
						return false;
					pPtr += 2;
				}
				return true;
			}
		}
		if (p[pPtr + 1] != '*')
		{
			if (s[sPtr] == p[pPtr] || p[pPtr] == '.')
				return match(s, p, sPtr + 1, pPtr + 1);
			else
				return false;
		}
		else
		{
			while ((p[pPtr] == s[sPtr] || p[pPtr] == '.') && sPtr != sSize)
			{
				if (match(s, p, sPtr, pPtr + 2))
					return true;
				sPtr++;
			}
		}
		return match(s, p, sPtr, pPtr + 2);
	}
};

int main()
{
	Solution s;
	cout<<s.isMatch("", "c*c*");
	system("Pause");
}
#include<iostream>
using namespace std;

class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0)
			return false;
		int base = 1;
		int temp = x;
		while (temp>=10)
		{
			base *= 10;
			temp /= 10;
		}
		while (x)
		{
			int left = x / base;
			int right = x - x / 10 * 10;
			if (left != right)
				return false;
			x -= left*base;
			x /= 10;
			base /= 100;
		}
		return true;
	}
};

int main()
{
	Solution s;
	cout<<s.isPalindrome(1001);
	system("Pause");
}
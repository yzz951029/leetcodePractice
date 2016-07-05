#include<iostream>
using namespace std;

class Solution {
public:
	int reverse(int x) {
		int add(0);
		int result = 0;
		bool positive = x > 0 ? true : false;
		if (!positive)
			x = -x;
		if (x == -INT_MAX - 1)
			return 0;
		while (x != 0)
		{
			if (result > INT_MAX / 10)
				return 0;
			int add = x - x / 10 * 10;
			result = result * 10 + add;
			x = x / 10;
		}
		if (!positive)
			result = -result;
		return result;
	}
};

int main()
{
	Solution s;
	int x = -INT_MAX - 1;
	cout << s.reverse(x) << endl;
	system("Pause");
}
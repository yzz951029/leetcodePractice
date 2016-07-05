#include<iostream>
using namespace std;

class Solution {
public:
	int myAtoi(string str) {
		int index = 0;
		bool positive = 0;
		int size = str.size();
		while (str[index] == ' ')
			index++;
		if (str[index] == '-')
		{
			positive = false;
			++index;
		}
			
		else if (str[index] == '+')
		{
			positive = true;
			++index;
		}
		else
			positive = true; 
		if (!(str[index] >= '0'&&str[index] <= '9'))
			return 0;
		int result = 0;
		int add = 0;
		while (index != str.size() && (str[index] >= '0'&&str[index] <= '9'))
		{
			add = str[index] - '0';
			if (result > INT_MAX / 10)
			{
				if (positive)
					return INT_MAX;
				else
					return INT_MIN;
			}
			result = result * 10 + add;
			index++;
		}
		if (positive&&result > 0)
			return result;
		else if (positive && result < 0)
			return INT_MAX;
		else if (!positive &&result<0)
			return INT_MIN;
		else
			return -result;
	}
};

int main()
{
	Solution s;
	cout << s.myAtoi("-1");
	system("Pause");
}
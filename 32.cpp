class Solution
{
public:
	int longestValidParentheses(string s)
	{
		int size = s.size();
		bool *a = new bool[size];
		memset(a, false, size);
		stack<int> b;
		for (int i = 0; i < size; i++)
		{
			if (s[i] == '(')
				b.push(i);
			else if (s[i] == ')'&&!b.empty())
			{
				a[i] = true;
				a[b.top()] = true;
				b.pop();
			}
		}
		int max = 0;
		int curLen = 0;
		for (int i = 0; i < size; i++)
		{
			if (a[i] == true)
				curLen++;
			else
			{
				max = (max>curLen ? max : curLen);
				curLen = 0;
			}
		}
		if (curLen > max)
		{
			max = curLen;
		}
		return max;
	}
};
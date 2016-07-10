#include<string>
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
	vector<string> letterCombinations(string digits) {
		if (digits == "")
			return vector<string>{};
		string digital[10];
		digital[2] = "abc";
		digital[3] = "def";
		digital[4] = "ghi";
		digital[5] = "jkl";
		digital[6] = "mno";
		digital[7] = "pqrs";
		digital[8] = "tuv";
		digital[9] = "wxyz";
		vector<string> answer{ "" };
		int size = digits.size();
		for (int i = 0; i<size; i++)
		{
			int s = answer.size();
			for (int j = 0; j < s; j++)
			{
				int digSize = digital[digits[i] - '0'].size();
				for (int k = 0; k<digSize; k++)
				{
					answer.push_back(answer[j] + digital[digits[i] - '0'][k]);
				}
			}
			answer.erase(answer.begin(), answer.begin() + s);
		}
		return answer;
	}
};

int main()
{
	Solution s;
	vector<string> a(s.letterCombinations(""));
	for (int i = 0; i < a.size(); i++)
		cout << a[i] << " ";
	system("Pause");
}
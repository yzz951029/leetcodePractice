#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int m = nums1.size();
		int n = nums2.size();
		int total = m + n;
		if ((total & 1) == 1)
			return findKth(nums1, m, nums2, n, total / 2 + 1);
		else
			return (findKth(nums1, m, nums2, n, total / 2) + findKth(nums1, m, nums2, n, total / 2 + 1)) / 2;
	}
	double findKth(vector<int> num1, int m, vector<int> num2, int n, int kth)
	{
		if (m > n)
			return findKth(num2, n, num1, m, kth);
		if (m == 0)
			return num2[kth - 1];
		if (kth == 1)
			return num1[0] > num2[0] ? num2[0] : num1[0];
		int pa = kth / 2 > m ? m : kth / 2;
		int pb = kth - pa;
		if (num1[pa - 1] < num2[pb - 1])
		{
			num1.erase(num1.begin(), num1.begin() + pa);
			return findKth(num1, m - pa, num2, n, kth - pa);
		}
		else if (num1[pa - 1]>num2[pb - 1])
		{
			num2.erase(num2.begin(), num2.begin() + pb);
			return findKth(num1, m, num2, n - pb, kth - pb);
		}	
		else
			return num1[pa - 1];
	}
};

int main()
{
	Solution s;
	vector<int> num1{2};
	vector<int> num2{};
	cout<<s.findMedianSortedArrays(num1, num2);
	system("Pause");
}
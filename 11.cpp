class Solution {
public:
	int maxArea(vector<int>& height) {
		int i = 0;
		int j = height.size() - 1;
		int max = 0;
		while (i != j)
		{
			int h = height[i] > height[j] ? height[j] : height[i];
			if ((j - i)*h>max)
				max = (j - i) * h;
			if (height[i]<height[j])
				i++;
			else
				j--;
		}
		return max;
	}
};
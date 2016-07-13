class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int size = nums.size();
        int cnt = 0;
        for(int i = 0;i < size;i++)
        {
            if(nums[i] == val)
            {
                continue;
            }
            else
            {
                nums[cnt]=nums[i];
                cnt++;
            }
        }
        return cnt;
    }
};
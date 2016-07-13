class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        if(size == 0)
            return 0;
        int cnt = 1;
        for(int i = 1;i < size;i++)
        {
            if(nums[i] == nums[i - 1])
            {
                continue;
            }
            else
            {
                nums[cnt] = nums[i];
                cnt++;
            }
        }
        return cnt;
    }
};
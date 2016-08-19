class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int size = nums.size();
        if(nums[0] > target)
            return 0;
        if(nums[size-1] < target)
            return size;
        for(int i = 1;i < size;i++)
        {
            if(nums[i] == target)
                return i;
            if(nums[i-1]<target && nums[i]>target)
                return i ;
        }
        return 0;
    }
};
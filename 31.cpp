class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int size = nums.size();
        int index = 0;
        //bool falg = false;
        bool des = true;
        for(int i = size-2;i >= 0;--i)
        {
            bool falg = false;
            for(int j=i+1;j<size;j++)
            {
                if(nums[i] < nums[j])
                {
                    index = i;
                    falg = true;
                    des = false;
                    break;
                }
            }
            if(falg)
                break;
        }
        if(des)
        {
            sort(nums.begin(),nums.end());
            return ;
        }
        int min=INT_MAX;
        int swapPos = 0;
        for(int i = index + 1;i<size;i++)
        {
            if(nums[i] > nums[index]&&nums[i]<min)
            {
                min = nums[i];
                swapPos = i; 
            }
        }
        int temp = nums[swapPos];
        nums[swapPos] = nums[index];
        nums[index] = temp;
        sort(nums.begin()+index+1,nums.end());
    }
};
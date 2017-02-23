class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        solu(nums,0,ans);
        return ans;
    }
    void solu(vector<int> &nums,int begin,vector<vector<int>> &ans)
    {
        if(begin>=nums.size())
        {
            ans.push_back(nums);
            return;
        }
        for(int i=begin;i<nums.size();i++)
        {
            swap(nums[i],nums[begin]);
            solu(nums,begin+1,ans);
            swap(nums[i],nums[begin]);
        }
    }
};


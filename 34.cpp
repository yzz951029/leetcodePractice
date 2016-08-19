class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
            vector<int> ans;
            ans.push_back(-1);
            ans.push_back(-1);
            ans[0] = searchBound(nums,target,true);
            ans[1] = searchBound(nums,target,false);
            return ans;
    }
    int searchBound(vector<int>& nums,int target,bool left)
    {
        int l = 0;
        int r = nums.size() - 1;
        int mid = (l+r)/2;
        int re = -1;
        while(l <= r)
        {
           if(nums[mid]<target)
           {
               l = mid + 1;
               mid =(l+r)/2;
           }
           else if(nums[mid]>target)
           {
               r = mid - 1;
               mid = (l+r)/2;
           }
           else if(nums[mid] == target)
           {
               re = mid;
               if(left)
                    r = mid-1;
                else
                    l = mid +1;
                mid = (l + r)/2;
           }
        }
        return re;
    }
};
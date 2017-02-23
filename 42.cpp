class Solution {
public:
    int trap(vector<int>& height) {
        int trapWater=0;
        for(int i=1;i<height.size();i++)
        {
            int ptr1=i - 1;
            int ptr2=i + 1;
            int h1=0;
            int h2=0;
            while(ptr1>=0)
            {
                if(height[ptr1]>h1)
                    h1=height[ptr1];
                ptr1--;
            }
            while(ptr2<height.size())
            {
                if(height[ptr2]>h2)
                    h2=height[ptr2];
                ptr2++;
            }
            int minH=(h1>h2?h2:h1);
            if(height[i]<minH)
                trapWater+=minH-height[i];
        }
        return trapWater;
    }
};
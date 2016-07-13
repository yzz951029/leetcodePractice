class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle=="")
            return 0;
        int sizeN = needle.size();
        int sizeH = haystack.size();
        for(int i=0;i <= sizeH-sizeN;i++)
        {
            bool flag=true;
            for(int j=0;j<sizeN;j++)
            {
                if(needle[j]!=haystack[i+j])
                    {
                        flag = false;
                        break;
                    }
            }
            if(flag)
            return i;
        }
        return -1;
    }
};
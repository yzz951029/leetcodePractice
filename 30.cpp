class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        if(s.size() == 0||words.size()==0)
            return ans;
        int wlen = words[0].size();
        int slen = (int)s.size();
        int wSize = (int)words.size();
        map<string,int> x;
        x.clear();
        for(int i = 0;i<words.size();i++)
            x[words[i]]++;
        for(int i = 0;i+wlen * wSize<=s.size();i++)
        {
            map<string,int> temp(x);
            bool flag = true;
            for(int j = 0;j<wSize;j++)
            {
                string sub = s.substr(i+j*wlen,wlen);
                if(temp[sub] == 0)
                {
                    flag = false;
                    break;
                }
                else
                    --temp[sub];
            }
            if(flag)
                ans.push_back(i);
        }
        return ans;
    }
};
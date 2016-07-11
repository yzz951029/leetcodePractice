class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        generate(n,n,"",result);
        return result;
    }
    void generate(int leftNum,int rightNum,string s,vector<string> &a)
    {
        if(leftNum == 0 && rightNum == 0)
        {
            a.push_back(s);
        }
        if(leftNum>0)
        {
            generate(leftNum-1,rightNum,s+'(',a);
        }
        if(rightNum>0 && leftNum < rightNum)
        {
            generate(leftNum,rightNum-1,s+')',a);
        }
    }
};
//这个算法可以好好学习一下
//http://blog.csdn.net/yutianzuijin/article/details/13161721
#include<stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        stack<char> a;
        int i=0;
        int size=s.size();
        if(size%2!=0)
            return false;
        for(;i<size;i++)
        {
            if(s[i]=='('||s[i]=='{'||s[i]=='[')
                a.push(s[i]);
            else
            {
                if(a.size()==0)
                    return false;
                char x=a.top();
                if(x=='('&&s[i]!=')')
                    return false;
                if(x=='['&&s[i]!=']')
                    return false;
                if(x=='{'&&s[i]!='}')
                    return false;
                a.pop();
            }
        }
        if(a.size() == 0)
            return true;
        else
            return false;
    }
};
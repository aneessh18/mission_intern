
bool isbalance(string s)
{
    stack <char> st;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='(')
            st.push(s[i]);
        else
        {
            if(st.empty()||st.top()!='(')
                return false;
            else
                st.pop();
        }
    }
    return st.empty();
}
void generate(string s,vector <string> &ans,int i,int n)
{
    if(i==n &&isbalance(s))
    {
         ans.push_back(s);
        return ;
    }
    else if(i==n)
    {
          return ;
    }
    else
    {
        generate(s+'(',ans,i+1,n);
        generate(s+')',ans,i+1,n);
    }
        
}
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector <string> ans;
        generate("",ans,0,2*n);
        return ans;
    }
};

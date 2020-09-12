#include <bits/stdc++.h>
using namespace std;
bool ischar(char x)
{
    if(x>='a'&&x<='z')
    return true;
    else if(x>='A'&&x<='Z')
    return true;
    else
    return false;
}
int precedence(char x)
{
    if(x=='^')
    return 5;
    else if(x=='/'&&x=='*')
    return 4;
    else if(x=='+'&&x=='-')
    return 3;
}
bool isop(char x)
{
  if(x=='^'||x=='+'||x=='-'||x=='*'||x=='/')
  return true;
  else
  return false;
}
int main() {
	//code
	int t;
	cin>>t;
	while(t--)
	{
	    stack <char> st;
	    string s;
	    cin>>s;
	    for(int i=0;i<s.length();i++)
	    {
	        if(ischar(s[i]))
	        cout<<s[i];
	        else if(s[i]=='(')
	        st.push(s[i]);
	        else if(s[i]==')')
	        {
	            while(st.top()!='(')
	            {
	                cout<<st.top();
	                st.pop();
	            }
              st.pop();
	        }
	        else if(isop(s[i]))
	        {
	              while(!st.empty()&&precedence(st.top())>=precedence(s[i]))
	                {
                    //cout<<precedence(s[i])<<" "<<precedence(st.top())<<"\n";
	                    cout<<st.top();
                        st.pop();
                   }
	                    st.push(s[i]);
	            }
	        }
      while(!st.empty())
      {
        cout<<st.top();
        st.pop();
      }
      cout<<"\n";
	}
	return 0;
}

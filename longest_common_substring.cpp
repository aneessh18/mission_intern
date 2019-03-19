#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s1,s2,ans="";
    cin>>s1>>s2;
    int n1=s1.length(),n2=s2.length();
    string buff1="",buff2="";
    for(int i=0;i<n1;i++)
    {
        for(int j=i;j<n1;j++)
        {
            buff1="";
            for(int k=i;k<=j;k++)
            {
                buff1+=s1[k];
            }
            for(int p=0;p<n2;p++)
            {
                for(int q=p;q<n2;q++)
                {
                    buff2="";
                    for(int r=p;r<=q;r++)
                    {
                        buff2+=s2[r];
                    }
                    if(buff1==buff2)
                    {
                        if(buff1.length()>ans.length())
                            ans=buff1;
                    }
                }
            }
        }
    }
    cout<<ans<<"\n";
}

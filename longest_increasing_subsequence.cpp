#include <bits/stdc++.h>
using namespace std;
int lis(int a[],int n) // dp solution
{
    int dp[n];
    dp[0]=1;
    for(int i=1;i<n;i++)
    {
        dp[0]=1;
        int q=INT_MIN;
        for(int j=0;j<i;j++)
        {
            if(a[i]>a[j])
            {
                q=max(q,1+dp[j]);
            }
            else
            {
                q=max(q,dp[j]);
            }
        }
        dp[i]=q;
    }
    return dp[n-1];
}
int main()
{
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    int ans=lis(a,n);
    cout<<ans<<"\n";
}

#include <bits/stdc++.h>
using namespace std;
int maxSubArray(int A[],int n)
{
    int dp[n],ans;
    dp[0]=A[0],ans=A[0];
    for(int i=1;i<n;i++)
    {
        dp[i]=max(dp[i-1]+A[i],A[i]);
        ans=max(ans,dp[i]);
    }
    return ans;
}
int main()
{
  int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++)
  cin>>a[i];
  int ans=maxSubArray(a,n);
  cout<<ans<<"\n";
}

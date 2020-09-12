#include <bits/stdc++.h>
using namespace std;
bool subset(int a[],int i,int sum1,int sum2,int n) // recusrsive solution
{
  if(i==n&& sum1==sum2)
  {
    return true;
  }
  else if(i==n &&sum1!=sum2)
  {
    return false;
  }
  else
  {
    return subset(a,i+1,sum1+a[i],sum2,n)||subset(a,i+1,sum1,sum2+a[i],n);
  }
}
bool subsetdp(int a[],int n)
{
  int sum=0;
  for(int i=0;i<n;i++)
  sum+=a[i];
  if(sum%2!=0)
  return false;
  sum/=2;
  bool dp[n+1][sum+1];
  for(int i=0;i<=n;i++)
  {
    dp[i][0]=true;
  }
  for(int i=1;i<=sum;i++)
  {
    dp[0][i]=false;
  }
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=sum;j++)
    {
      if(a[i-1]>j)
      dp[i][j]=dp[i-1][j];
      else
      dp[i][j]=dp[i-1][j]||dp[i-1][j-a[i-1]];
    }
  }
  return dp[n][sum];
}
int main()
{
  int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++)
  cin>>a[i];

  bool ans=subsetdp(a,n);
  if(ans)
  cout<<"YES";
  else
  cout<<"NO";
}

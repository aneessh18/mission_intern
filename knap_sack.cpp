#include <bits/stdc++.h>
using namespace std;
int knap_sack(int w[],int p[],int n,int k)
{
  int dp[n+1][k+1];
  for(int i=0;i<=n;i++)
  dp[i][0]=0;
  for(int i=1;i<=k;i++)
  dp[0][i]=0;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=k;j++)
    {
      dp[i][j]=dp[i-1][j];
      if(j>=w[i-1])
      dp[i][j]=max(dp[i][j],dp[i-1][j-w[i-1]]+p[i-1]);
    }
  }
  return dp[n][k];
}
int main()
{
  int n;
  cin>>n;
  int w[n],p[n];
  for(int i=0;i<n;i++)
    cin>>w[i];
  for(int i=0;i<n;i++)
  cin>>p[i];
  int weight;
  cin>>weight;
  int ans=knap_sack(w,p,n,weight);
  cout<<ans<<"\n";
}

#include <bits/stdc++.h>
using namespace std;
int n,m,a[105][105];
int mcp(int i,int j)
{
  if(i>=n||j>=m)
  return INT_MAX;
  else if(i==n-1&&j==m-1)
  return a[i][j];
  else
  return a[i][j]+min(mcp(i+1,j),min(mcp(i,j+1),mcp(i+1,j+1)));
}
int main()
{
  cin>>n>>m;

  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    cin>>a[i][j];
  }
  int ans=mcp(0,0);
  cout<<ans<<"\n"; // naive recursive solution

  int cost[n][m];
  cost[0][0]=a[0][0];
  for(int i=1;i<m;i++)
  {
    cost[0][i]=a[0][i]+cost[0][i-1];
  }
  for(int i=1;i<n;i++)
  {
    cost[i][0]=a[i][0]+cost[i-1][0];
  }
  for(int i=1;i<n;i++)
  {
    for(int j=1;j<m;j++)
    {
      cost[i][j]=a[i][j]+min(cost[i-1][j],min(cost[i][j-1],cost[i-1][j-1]));
    }
  }
  cout<<cost[n-1][m-1]<<"\n";
}

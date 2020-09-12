#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++)
  cin>>a[i];
  int dp[n];
  dp[0]=1;
  dp[n-1]=1;
  for(int i=1;i<n-1;i++)
  {
    int p1=1,p2=1,j=i,k=i;
    while(j>0&&a[j-1]<a[j])
    p1++,j--;
    while(k<n-1&&a[k]>a[k+1])
    p2++,k++;
    dp[i]=max(p1,p2);
  }
  int ans=0;
  for(int i=0;i<n;i++)
  ans+=dp[i];
  cout<<ans<<"\n";
}

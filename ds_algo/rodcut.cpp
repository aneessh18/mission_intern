#include <bits/stdc++.h>
using namespace std;
int max_profit(int a[],int n)
{
  if(n==0)
  return 0;
  int q=INT_MIN;
  for(int i=1;i<=n;i++)
  {
    q=max(q,a[i]+max_profit(a,n-i));
  }
  return q;
}
int main()
{
  int n;
  cin>>n;
  int a[n+1];
  for(int i=1;i<=n;i++)
  cin>>a[i];
  int ans=max_profit(a,n);
  cout<<ans<<"\n";
}

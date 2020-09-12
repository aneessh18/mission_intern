#include <bits/stdc++.h>
using namespace std;
int stairs(int n,int k) // recursive solution
{
    if(k>n)
        return 0;
    else if(k==n)
        return 1;
    else
        return stairs(n,k+1)+stairs(n,k+2)+stairs(n,k+3);
}
int stairsdp(int n)
{
    int dp[n+1];
    dp[0]=1;
    dp[1]=1;
    dp[2]=2;
    for(int i=3;i<=n;i++)
        dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
    return dp[n];
}
int main()
{
  int t;
  cin>>t;
  while(t--)
  {
          int n;
    cin>>n;
    int ans1=stairs(n,0);
    int ans2=stairsdp(n);
    cout<<ans1<<" "<<ans2<<"\n";
    if(ans1==ans2)
    {
        cout<<"recursion is base to dp"<<"\n";
    }
    else
    {
        cout<<"stupid";
    }
  }
}

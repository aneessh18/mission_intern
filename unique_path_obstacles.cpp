#include <bits/stdc++.h>
using namespace std;
int g[100][100];
int n,m;
int countpath(int i,int j)
{
    if(i>=n||j>=m)
        return 0;
    else if(g[i][j]==1)
        return 0;
    else if(i==n-1&&j==m-1)
        return 1;
    else
        return countpath(i+1,j)+countpath(i,j+1);
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            g[i][j]=0;
    }
    int t;
    cin>>t;
     while(t--)
     {
         int x,y;
         cin>>x>>y;
         g[x][y]=1;
     }
     int ans=countpath(0,0);
     cout<<ans<<"\n";
}

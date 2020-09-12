class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
     int n=dungeon.size();
        if(n==0)
            return 0;
        int m=dungeon[0].size();
        int dp[n][m];
        
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                if(i==n-1 && j==m-1)
                {
                    dp[i][j]=max(1,1-dungeon[i][j]);
                }
                else if(i==n-1)
                {
                    dp[i][j]=max(1,dp[i][j+1]-dungeon[i][j]);
                }
                else if(j==m-1)
                {
                    dp[i][j]=max(1,dp[i+1][j]-dungeon[i][j]);
                }
                else
                {
                    int down=max(dp[i+1][j]-dungeon[i][j],1);
                    int right=max(dp[i][j+1]-dungeon[i][j],1);
                    dp[i][j]=min(down,right);
                }
            }
        }
        return dp[0][0];
    }
    
};

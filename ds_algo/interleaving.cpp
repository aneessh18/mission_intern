bool interleave(string s1,string s2,string s3,int i,int j,int k)
{
    if(s1.length()==i || s2.length()==j || s3.length()==k)
        return true;
    else
    {
        return ((s3[k]==s1[i] && interleave(s1,s2,s3,i+1,j,k+1)) || (s3[k]==s2[j] && interleave(s1,s2,s3,i,j+1,k+1)));
    }
}
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
     int n=s1.length(),m=s2.length(),len=s3.length();
        if(n+m!=len)
            return false;
        bool dp[n+1][m+1];
        memset(dp,false,sizeof dp);
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                if(i==0 && j==0) // empty string case
                    dp[i][j]=true;
                else if(i==0)
                    dp[i][j]=(s2[j-1]==s3[j-1] && dp[i][j-1]);
                else if(j==0)
                    dp[i][j]=(s1[i-1]==s3[i-1] && dp[i-1][j]);
                else
                {
                    dp[i][j]=((s1[i-1]==s3[i+j-1] && dp[i-1][j]) || (s2[j-1]==s3[i+j-1] && dp[i][j-1]));
                }
            }
        }
        return dp[n][m];
    }
};

string lcs(string s1,string s2)
{
    int n1=s1.length(),n2=s2.length(),dp[n1+1][n2+1];
    for(int i=0;i<=n1;i++)
    {
        for(int j=0;j<=n2;j++)
        {
            if(i==0)
                dp[i][j]=j;
            else if(j==0)
                dp[i][j]=i;
            else if(s1[i-1]==s2[j-1])
                dp[i][j]=1+dp[i-1][j-1];
            else
                dp[i][j]=1+min(dp[i-1][j],dp[i][j-1]);
        }
    }
    int i=n1,j=n2;
    string buff="";
    while(i>0 && j>0)
    {
        if(s1[i-1]==s2[j-1])        {
             buff=s1[i-1]+buff;
            i--,j--;
        }
        else if(dp[i-1][j]<dp[i][j-1])
        {
            buff=s1[--i]+buff;
        }
        else
        {
            buff=s2[--j]+buff;
        }
    }
    while(i>0)
    {
        buff=s1[--i]+buff;
    }
    while(j>0)
    {
        buff=s2[--j]+buff;
    }
    return buff;
}
class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        return lcs(str1,str2);
    }
};

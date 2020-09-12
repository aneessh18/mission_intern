class Solution {
public:
    string longestPalindrome(string s) {
        if(s.length()==0||s.length()==1)
            return s;
        int n=s.length();
        bool dp[n][n];
        for(int i=0;i<n;i++)
        {
          for(int j=0;j<n;j++)
          dp[i][j]=false;
        }
        for(int i=0;i<n;i++)
            dp[i][i]=true;
        int st=0,len=1;
        for(int i=0;i<n-1;i++)
        {
            if(s[i]==s[i+1])
            {
                dp[i][i+1]=true;
                st=i;
                len=2;
            }
        }
        for(int k=3;k<=n;k++)
        {
            for(int i=0;i<n-k+1;i++)
            {
                int j=i+k-1;
                if(dp[i+1][j-1]&&s[i]==s[j])
                {
                    dp[i][j]=true;
                    if(k>len)
                    {
                        st=i;
                        len=k;
                    }
                }
            }
        }
        string ans="";
        for(int i=st;i<st+len;i++)
            ans+=s[i];
          return ans;
    }
};

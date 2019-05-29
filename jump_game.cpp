bool jump(int i,vector<int> &nums)
{
    int n=nums.size();
    bool dp[n];
    dp[0]=true;
    for(int i=1;i<n;i++)
        dp[i]=false;
    for(int i=0;i<n-1;i++)
    {
        if(dp[i]==true)
        {
            for(int j=1;j<=nums[i];j++)
            {
                if(i+j<n)
                    dp[i+j]=true;
            }
        }
        else
            return false;
    }
    return dp[n-1];
        
}
class Solution {
public:
    bool canJump(vector<int>& nums)
    {
        if(jump(0,nums))return true;
        else return false;
    }
};

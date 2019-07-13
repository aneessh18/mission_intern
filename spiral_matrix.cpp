#define pb  push_back
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector <int> ans;
        int m=matrix.size();
        if(m==0)
            return ans;
        int n=matrix[0].size();
        int l=0,h=0,i,j;
        while(l<m && h<n)
        {
            for(i=h;i<n;i++)
                ans.pb(matrix[l][i]);
            l++;
            for(j=l;j<m;j++)
                ans.pb(matrix[j][n-1]);
            n--;
            if(l<m)
            {
                for(j=n-1; j>=h ;j--)
                    ans.pb(matrix[m-1][j]);
                m--;
            }
            if(h<n)
            {
                for(i=m-1;i>=l;i--)
                    ans.pb(matrix[i][h]);
                h++;
            }
        }
        return ans;
    }
};

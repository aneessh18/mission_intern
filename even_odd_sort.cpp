class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& a) {
        int n=a.size();
        if(n==0)
            return a;
        int l=0,r=n-1;
        while(l<r)
        {
            if(a[l]%2==1)
            {
                swap(a[l],a[r]);
            }
            else
                l++;
             if(a[r]%2==0)
            {
                swap(a[l],a[r]);
            }g
            else
            r--;
        }
     return a;   
    }
};

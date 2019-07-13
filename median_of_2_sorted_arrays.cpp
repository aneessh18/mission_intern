class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size(),m=nums2.size(),i,j,median;
        int len=min(n,m);
        int min_index=0,max_index=len;
        vector <int> a,b;
        if(len==n)
        {
            a=nums1;
            b=nums2;
        }
        else
        {
            a=nums2;
            b=nums1;
            swap(n,m);
        }
        while(min_index<=max_index)
        {
            i=(min_index+max_index)/2;
            j=((n+m+1)/2)-i;
            if(i<n && j>0 && b[j-1]>a[i]) // b2 > a2 move to right side
                min_index=i+1;
            else if(i>0 && j<m && a[i-1]>b[j]) // a1>b3 move to left side
                max_index=i-1;
            else
            {
                if(i==0 && j>0)
                    median=b[j-1];
                else if(j==0 && i>0)
                    median=a[i-1];
                else
                    median=max(a[i-1],b[j-1]);
                break;
            }
        }
        if((n+m)%2==1)
            return (double)median;
        if(i==n)
            return (median+b[j])/2.0;
        if(j==m)
            return (median+a[i])/2.0;
        return (median+min(a[i],b[j]))/2.0;
    }
};

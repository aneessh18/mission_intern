int merge(vector <int> &A,int low,int mid,int high)
{
    vector <int> temp;
    int i=low,j=mid+1;
    int inv_count=0;
    while(i<=mid && j<=high)
    {
        if(A[i]<=A[j])
        {
            temp.push_back(A[i]);
            i++;
        }
        else
        {
            temp.push_back(A[j]);
            j++;
            inv_count+=mid-i+1;
        }
    }
    while(i<=mid)
        temp.push_back(A[i++]);
    while(j<=high)
        temp.push_back(A[j++]);
    i=0;
    for(int k=low;k<=high;k++)
        A[k]=temp[i++];
    return inv_count;
}
int merge_sort(vector <int>& A,int low,int high)
{
    int inv_count=0;
   if(low<high)
   {
       int mid=(low+high)/2;
       inv_count+=merge_sort(A,low,mid);
       inv_count+=merge_sort(A,mid+1,high);
       inv_count+=merge(A,low,mid,high);
   }
    return inv_count;
}

class Solution {
public:
    bool isIdealPermutation(vector<int>& A) {
     int local_inv=0,n=A.size();
        for(int i=0;i<n-1;i++)
        {
            if(A[i]>A[i+1])
                local_inv++;
        }
        int global_inv=merge_sort(A,0,A.size()-1);
        return (global_inv==local_inv);
    }
};

int noOfDaysWithCurrentMax(vector<int> weights, int maxCapacity)
{
    int no_of_days = 0;
    int sum = 0;
    for(int i=0;i<weights.size();i++)
    {
        if(sum+weights[i]<=maxCapacity)
        {
            sum += weights[i];
        }
        else{
            no_of_days++;
            if(maxCapacity<weights[i])
                return INT_MAX;
            sum = weights[i]; // reset the sum
        }
    }
    return (sum==0)?no_of_days:no_of_days+1;
}
class Solution {
public:
    int shipWithinDays(vector<int>& weights, int D) {
        int lo = 0;
        int hi = accumulate(weights.begin(),weights.end(),0); // sum of weights
        while(lo<hi)
        {
            int mid=(lo+hi)>>1;
            int noOfDaysWithMid = noOfDaysWithCurrentMax(weights, mid);
            // cout<<lo<<" "<<hi<<"\n";
            // cout<<noOfDaysWithMid<<" "<<mid<<"\n";
            if(noOfDaysWithMid<=D)
            {
                hi = mid;
            }
            else{
                lo = mid+1;
            }
        }
        // cout<<lo<<" "<<hi<<"\n";
        return lo;
    }
};
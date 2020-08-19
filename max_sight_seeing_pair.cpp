class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& A) {
        int n = A.size();
        int max_before = A[0];
        int max_score = -1;
        for(int i=1;i<n;i++)
        {
            max_score = max(max_score, A[i]-i+max_before);
            max_before = max(max_before, A[i]+i);
        }
        return max_score;
    }
};
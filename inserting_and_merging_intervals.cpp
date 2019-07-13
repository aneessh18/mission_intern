class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector <pair<int,int>> v;
        for(int i=0;i<intervals.size();i++)
        {
            v.push_back({intervals[i][0],intervals[i][1]});
        }
        v.push_back({newInterval[0],newInterval[1]});
        sort(v.begin(),v.end());
        stack <pair<int,int>> st;
        for(auto i : v)
        {
                st.push({i.first,i.second});
                while(st.size()>1)
                {
                    pair<int,int> temp1,temp2;
                    temp2=st.top();
                    st.pop();
                    temp1=st.top();
                    st.pop();
                    if(temp1.second<temp2.first)
                    {
                        st.push(temp1);
                        st.push(temp2);
                        break;
                    }
                    else
                    {
                       
                        temp1.second=max(temp1.second,temp2.second);
                        st.push(temp1);
                    }
                }
        }
        intervals.clear();
        while(!st.empty())
        {
            vector <int> p(2);
            p[0]=st.top().first;
            p[1]=st.top().second;
            st.pop();
            intervals.push_back(p);
        }
        reverse(intervals.begin(),intervals.end());
        return intervals;
    }
};

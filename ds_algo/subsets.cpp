#include <bits/stdc++.h>
using namespace std;
map <vector<int>,int> mp;
void decode(string s,vector <int> &nums)
{
    vector<int> p;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='1')
            p.push_back(nums[i]);
            cout<<s[i]<<" ";
    }
    cout<<"\n";
    mp[p]++;
}
void subset(int i,vector <int> &nums,string s)
{
    if(i==nums.size())
    {
        decode(s,nums);
    }
    else
    {
        subset(i+1,nums,s+'0');
        subset(i+1,nums,s+'1');
    }
}
int main()
{
  int n;
  cin>>n;
  vector <int> nums;
  int x;
  for(int i=0;i<n;i++)
  {
    cin>>x;
    nums.push_back(x);
  }
  subset(0,nums,"");
  map < vector<int>,int > ::iterator itr;
  for(itr=mp.begin();itr!=mp.end();itr++)
    {
        for(int j=0;j<itr->first.size();j++)
          {
                cout<<itr->first[j]<<" ";
            }
            cout<<"\n";
        }
}

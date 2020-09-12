bool isvalid(int i,int j, int n, int m)
{
    return i>=0 && j>=0 && i<n && j<m;
}
class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        // dist b/w water and land should be maximized
        // dist b/w land and water 
        queue < pair<pair<int,int>,int> > q;
        int n = grid.size();
        int m = grid[0].size();
        int dist[n][m];
        memset(dist, 0, sizeof(dist));
        bool visit[n][m];
        memset(visit, false, sizeof(visit));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 1)
                {
                    visit[i][j] = true;
                    q.push({{i,j},0});
                }
            }
        }
        int ans = -1;
        while(!q.empty())
        {
            auto top = q.front();
            q.pop();
            int dis = top.second;
            int x = top.first.first;
            int y = top.first.second;
            dist[x][y] = dis;
            cout<<x<<" "<<y<<" "<<dis<<endl;
            ans = max(ans, dis);
            int direcs[4][2] = {{0,-1},{0,1},{1,0},{-1,0}};
            for(auto direc : direcs)
            {
                int point_x = x + direc[0];
                int point_y = y + direc[1];
                if(isvalid(point_x, point_y, n, m) && !visit[point_x][point_y] && grid[point_x][point_y] == 0)
                {
                    visit[point_x][point_y] = true;
                    q.push({{point_x,point_y},dis+1});
                }
            }
        }
        return ans == 0 ? -1 : ans;
    }
};
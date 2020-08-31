int height(vector<int> graph[], bool visit[], int x)
{
    visit[x] = true;
    int depth = 0;
    for(auto neigh:graph[x])
    {
        if(!visit[neigh])
        {
            depth = max(depth, height(graph, visit, neigh));
        }
    }
    return depth+1;
}
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        // first construct the graph and then perform dfs frome every node
        // brute force
        if(edges.empty())
            return {0};
        vector<int> graph[n];
        // bool visit[n];
        // memset(visit, false, n);
        vector<int> degrees(n,0);
        for(auto edge:edges)
        {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
            degrees[edge[0]]++;
            degrees[edge[1]]++;
        }
        // map<int, vector<int> > height_trees;
        // for(int i=0;i<n;i++)
        // {
        //     height_trees[height(graph, visit, i)].push_back(i);
        //     memset(visit, false, n);
        // }
        // auto iter = height_trees.begin();
        // return iter->second;
        
        vector<int> leaves;
        for(int i=0;i<degrees.size();i++)
        {
            if(degrees[i] == 1)
            {
                leaves.push_back(i);
            }
        }
        while (n > 2)
        {
            n -= leaves.size();
            vector<int> newleaves;
            for(auto leave:leaves)
            {
                for(auto neigh: graph[leave])
                {
                    if(--degrees[neigh] == 1)
                    {
                        newleaves.push_back(neigh);
                    }
                }
            }
            leaves = newleaves;
        }
        return leaves;
    }
    //its a brilliant solution traversing from the leaves 
    //the root of the MHT would contain may leaves
    
};
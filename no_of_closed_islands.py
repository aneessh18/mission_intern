def isvalid(i,j,n,m):
    return i>=0 and j>=0 and i<n and j<m
def iscorner(i,j,n,m):
    return i==0 or j==0 or i==n-1 or j==m-1
class Solution:
    def closedIsland(self, grid: List[List[int]]) -> int:
        
        #loop over the grid and find the connected components which doesn't have borders
        n = len(grid)
        m = len(grid[0])
        visit = [[False for j in range(m)] for i in range(n)]
        def dfs(i:int, j:int):
            visit[i][j] = True
            direcs = [[0,1],[1,0],[-1,0],[0,-1]]
            if iscorner(i, j,n,m):
                return False
            flag = True
            for direc in direcs:
                
                neigh_x = direc[0]+i
                neigh_y = direc[1]+j
                if isvalid(neigh_x, neigh_y, n, m) and  not visit[neigh_x][neigh_y] and grid[neigh_x][neigh_y] == 0 :    
                    
                    if not dfs(neigh_x, neigh_y):
                        flag = False
            
            return flag
        
        islands = 0
        
        for i in range(n):
            for j in range(m):
                if grid[i][j] == 0 and not iscorner(i,j,n,m) and not visit[i][j]:
                    if dfs(i,j):
                        print(i, j)
                        islands += 1
                    
                    
        return islands
                
                
"""
 [
    [0,0,1,1,0,1,0,0,1,0],
    [1,1,0,1,1,0,1,1,1,0],
    [1,0,1,1,1,0,0,1,1,0],
    [0,1,1,0,0,0,0,1,0,1],
    [0,0,0,0,0,0,1,1,1,0],
    [0,1,0,1,0,1,0,1,1,1],
    [1,0,1,0,1,1,0,0,0,1],
    [1,1,1,1,1,1,0,0,0,0],
    [1,1,1,0,0,1,0,1,0,1],
    [1,1,1,0,1,1,0,1,1,0]
 ]
 """
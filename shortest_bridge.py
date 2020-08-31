"""[[1,1,1,1,1],
    [1,0,0,0,1],
    [1,0,1,0,1],
    [1,0,0,0,1],
    [1,1,1,1,1]]"""
import collections 
class Solution:
    def shortestBridge(self, A: List[List[int]]) -> int:
        
        #first do a dfs and color one island
        #next do a bfs from the other island
        #do the numbering for the zeros

        n = len(A)
        m = len(A[0])
        visit = [[False for j in range(m)] for i in range(n)]

        def isvalid(i,j):
            return i>=0 and i<n and j>=0 and j<m
        def dfs(i,j):
            visit[i][j] = True
            A[i][j] = 2
            direcs = [[1,0],[0,1],[-1,0],[0,-1]]

            for direc in direcs:
               point_x, point_y = direc[0]+i, direc[1]+j
               if isvalid(point_x, point_y) and A[point_x][point_y] == 1 and not visit[point_x][point_y]:
                   dfs(point_x, point_y)
                
        queue = collections.deque()
        
        for i in range(n):
            for j in range(m):
                if A[i][j] == 1:
                    dfs(i,j)
                    break

                


        
        
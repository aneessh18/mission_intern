# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right


class Solution:
    def btreeGameWinningMove(self, root: TreeNode, n: int, x: int) -> bool:
            
        parent = collections.defaultdict(TreeNode)
        parent[root] = None
        num_to_node = collections.defaultdict(TreeNode)
        def findparent(root:TreeNode):
            if root :
                num_to_node[root.val] = root
                if root.left:
                    parent[root.left] = root
                if root.right:
                    parent[root.right] = root
                findparent(root.left)
                findparent(root.right)
                
        
        findparent(root)
        for i in range(1,n+1):
            if i != x:
                score_x = 0
                score_y = 0
                queue1 = deque()
                color = collections.defaultdict(int)
                queue1.append(num_to_node[x])
                color[num_to_node[x]] = 1
                queue2 = deque()
                queue2.append(num_to_node[i])
                color[num_to_node[i]] = 2
                turn = 'x'

                while len(queue1)>0 or len(queue2)>0:
                    if turn == 'x':
        
                        if len(queue1) > 0:
                            front = queue1.popleft()
                            print("red",front.val)
                            if front.left  and color[front.left] == 0:
                                color[front.left] = 1
                                queue1.append(front.left)
                                score_x += 1 
                            if front.right and color[front.right] == 0:
                                color[front.right] = 1
                                queue1.append(front.right)
                                score_x += 1 
                            if parent[front] != None and color[parent[front]] == 0:
                                color[parent[front]] = 1
                                queue1.append(parent[front])
                                score_x += 1

                        turn = 'y'
                            
                    else :
                        if len(queue2) > 0:
                            front = queue2.popleft()
                            print("blue",front.val)
                            if front.left  and color[front.left] == 0:
                                color[front.left] = 2
                                queue2.append(front.left)
                                score_y += 1 
                            if front.right and color[front.right] == 0:
                                color[front.right] = 2
                                queue2.append(front.right)
                                score_y += 1 
                            if parent[front] != None and color[parent[front]] == 0:
                                color[parent[front]] = 2
                                queue2.append(parent[front])
                                score_y += 1

                        turn = 'x'
                    
                
                if score_y > score_x:
                    return True
        
        return False
                           
                        
                            
                        
        
        
        
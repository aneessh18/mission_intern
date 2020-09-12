# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
def edgeNode(root, direc):
    if not root :
        return None
    if direc :
        while root.left:
            root = root.left
    else :
        while root.right:
            root = root.right
    return root
class Solution:
    def deleteNode(self, root: TreeNode, key: int) -> TreeNode:
        
        if root == None:
            return None
        if root.val == key:
            left = edgeNode(root.left, False)
            right = edgeNode(root.right, True)
            
            if left or right :
                print(root.val)
                root.val = right.val if right else left.val
                if right:
                    root.right = self.deleteNode(root.right, root.val)
                else :
                    root.left = self.deleteNode(root.left, root.val)
                
            else :
                root = None
        elif root.val>key:
            root.left = self.deleteNode(root.left, key)
        else :
            root.right = self.deleteNode(root.right, key)
            
        return root
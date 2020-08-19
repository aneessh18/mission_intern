def preorder(root, max_ances):
    if root!= None:
        # print(root.val)
        flag=0
        if max_ances<=root.val:
            flag=1
        return flag+preorder(root.left,max(max_ances,root.val))+preorder(root.right,max(max_ances,root.val))
    else :
        return 0
class Solution:
    def goodNodes(self, root: TreeNode) -> int:
        max_ances = -10**5
        good = 0
        return preorder(root,max_ances)
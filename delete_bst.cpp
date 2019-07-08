/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode *findmin(TreeNode *root)
{
    while(root->left)
        root=root->left;
    return root;
}
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL)
            return NULL;
        else  if(root->val>key)
        {
            root->left=deleteNode(root->left,key);
            return root;
        }
        else if(root->val<key)
        {
            root->right=deleteNode(root->right,key);
            return root;
        }
        else
        {
            if(root->left==NULL)
            return root->right;
             else if(root->right==NULL)
            return root->left;
            TreeNode *temp=findmin(root->right);
            root->val=temp->val;
            root->right= deleteNode(root->right,root->val);
        }
        return root;
    }
};

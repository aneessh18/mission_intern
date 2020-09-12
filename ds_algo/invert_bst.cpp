/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
void invert(TreeNode* root)
{
    if(root)
    {
        invert(root->left);
        invert(root->right);
        TreeNode *temp=root->right;
        root->right=root->left;
        root->left=temp;
    }
}
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        invert(root);
        return root;
    }
};

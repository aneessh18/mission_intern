/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> allPossibleFBT(int N) {
        if(N<=0 || N%2==0)
            return vector<TreeNode*> {};
        
        else
        {
            vector<TreeNode*> trees;
            if(N==1)
            {
                TreeNode *node = new TreeNode(0);
                trees.push_back(node);
                return trees;
            }
            
            for(int i=1;i<N;i+=2)
            {
                vector<TreeNode*> leftTrees = allPossibleFBT(i);
                vector<TreeNode*> rightTrees = allPossibleFBT(N-i-1);
                for(auto left:leftTrees)
                {
                    for(auto right:rightTrees)
                    {
                        TreeNode* root = new TreeNode(0);
                        root->left = left;
                        root->right = right;
                        trees.push_back(root);
                    }
                }
            }
            return trees;
        }
    }
};
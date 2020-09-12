/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int height(TreeNode *root,int x)
{
    queue <TreeNode*> q;
    q.push(root);
    q.push(NULL);
    int i=0;
    while(q.size()>1)
    {
        TreeNode *temp=q.front();
        q.pop();
        if(!temp)
        {
            i++;
            q.push(NULL);
        }
        else
        {
            if(temp->val==x)
                return i;
            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
        }
    }
    i++;
    return i;
    
}
TreeNode *preorder(TreeNode *root,int x)
{
    queue <TreeNode *> q;
    q.push(root);
    while(true)
    {
        TreeNode *temp=q.front();
        q.pop();
        if(temp->val==x)
            return temp;
        if(temp->left)
            q.push(temp->left);
        if(temp->right)
            q.push(temp->right);
    }
    return NULL;
    
}
TreeNode *Lca(TreeNode *root,int x,int y)
{
    if(!root)
        return NULL;
    if(root->val==x||root->val==y)
        return root;
    TreeNode *left=Lca(root->left,x,y);
    TreeNode *right=Lca(root->right,x,y);
    if(left && right)
        return root;
    root= (left) ? left : right;
    return root;
}
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        TreeNode *node1,*node2,*node3;
        node1=preorder(root,x);
        node2=preorder(root,y);
        int h1,h2;
        h1=height(root,x);
        h2=height(root,y);
        node3=Lca(root,x,y);
      //  cout<<node1->val<<" "<<node2->val<<"\n";
        //cout<<h1<<" "<<h2;
        if(h1==h2)
        {
            if(!node3->left||!node3->right)
                return true;
            else if(node3->left->val==x &&node3->right->val==y)
                return false;
            else if(node3->left->val==y &&node3->right->val==x)
                return false;
            else
                return true;
        }
        return false;
    }
};

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
    bool isBalanced(TreeNode* root) {
        return heightTree(root)!=-1;
    }

    int heightTree(TreeNode* root)
    {
        if(root==NULL)
        {
            return 0;
        }

        int lh=heightTree(root->left);
        if(lh==-1) return -1;
        int rh=heightTree(root->right);
        if(rh==-1) return -1;
        if(abs(lh-rh) >1) return -1;

        return max(lh,rh)+1;
    }
};
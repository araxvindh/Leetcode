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

    void toSolve(TreeNode*root,vector<string>&ans,string temp)
    {
        if(!root) return ;
        
        if(root->left==nullptr && root->right==nullptr)
        {
            temp+=to_string(root->val);
            ans.push_back(temp);
            return;
        }

        temp+=to_string(root->val) + "->";

        toSolve(root->left,ans,temp);
        toSolve(root->right,ans,temp);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;

        toSolve(root,ans,"");

        return ans;
    }
};
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

    void toSolve(TreeNode*root ,int sum ,vector<vector<int>>&ans,vector<int>&temp,int s)
    {
        if(!root)
        {
            return;
        }
        temp.push_back(root->val);
        s+=root->val;

        if(sum==s && root->left==nullptr && root->right==nullptr)
        {
            ans.push_back(temp);
        }

        toSolve(root->left,sum,ans,temp,s);
        toSolve(root->right,sum,ans,temp,s);

        temp.pop_back();
    }

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;
        vector<int>temp;

        toSolve(root,targetSum,ans,temp,0);

        return ans;
    }
};
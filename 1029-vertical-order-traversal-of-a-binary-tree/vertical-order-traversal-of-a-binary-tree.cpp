class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if (!root) return {};

      
        map<int, map<int, multiset<int>>> mpp;

        
        queue<pair<TreeNode*, pair<int, int>>> q;
        q.push({root, {0, 0}});

        while (!q.empty()) {
            TreeNode* node = q.front().first;
            int x = q.front().second.first;  
            int y = q.front().second.second; 
            q.pop();

            mpp[x][y].insert(node->val);

            if (node->left) {
                q.push({node->left, {x - 1, y + 1}}); 
            }
            if (node->right) {
                q.push({node->right, {x + 1, y + 1}}); 
            }
        }


        vector<vector<int>> ans;
        for (auto& p : mpp) {
            vector<int> col;
            for (auto& q : p.second) {
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }

        return ans;
    }
};

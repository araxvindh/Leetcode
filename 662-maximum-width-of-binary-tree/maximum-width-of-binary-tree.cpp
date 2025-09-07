class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        long long ans = 0;

        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});

        while (!q.empty()) {
            int size = q.size();
            unsigned long long mmin = q.front().second;  
            unsigned long long first = 0, last = 0;

            for (int i = 0; i < size; i++) {
                unsigned long long id = q.front().second - mmin; 
                TreeNode* node = q.front().first;
                q.pop();

                if (i == 0) first = id;
                if (i == size - 1) last = id;

                if (node->left) q.push({node->left, id * 2 + 1});
                if (node->right) q.push({node->right, id * 2 + 2});
            }

            ans = max(ans, (long long)(last - first + 1));
        }

        return (int)ans;
    }
};

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;

        long long ans = 0;

        // pair = (node, index)
        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 1});

        while (!q.empty()) {

            int size = q.size();

            unsigned long long start = q.front().second;

            unsigned long long first = 0, last = 0;

            for (int i = 0; i < size; i++) {
                auto p = q.front();
                q.pop();

                unsigned long long idx = p.second - start;  
                TreeNode* node = p.first;

                if (i == 0) first = idx;
                if (i == size - 1) last = idx;

                if (node->left)
                    q.push({node->left, idx * 2});
                if (node->right)
                    q.push({node->right, idx * 2 + 1});
            }

            ans = max(ans, (long long)(last - first + 1));
        }

        return ans;
    }
};

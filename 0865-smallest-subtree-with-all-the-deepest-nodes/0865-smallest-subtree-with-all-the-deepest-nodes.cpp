class Solution {

    public:
        TreeNode* dfs(TreeNode* node, int depth, int& maxDepth) {
            if (!node) {
                maxDepth = max(maxDepth, depth);
                return nullptr;
            }

            int leftMax = maxDepth;
            int rightMax = maxDepth;

            TreeNode* leftNode  = dfs(node->left,  depth + 1, leftMax);
            TreeNode* rightNode = dfs(node->right, depth + 1, rightMax);

            maxDepth = max(leftMax, rightMax);

            if (leftMax == rightMax)  return node;

            return (leftMax > rightMax) ? leftNode : rightNode;
        }
     
        TreeNode* subtreeWithAllDeepest(TreeNode* root) {
            int maxDepth = 0;
            return dfs(root, 0, maxDepth);
        }
};

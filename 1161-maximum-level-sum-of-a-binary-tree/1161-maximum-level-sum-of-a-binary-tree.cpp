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
    int maxLevelSum(TreeNode* root) {
        
        queue<TreeNode*> q;

        q.push(root);

        int maxSum = INT_MIN;
        int level = 1;

        int count = 1;

        while(!q.empty()){

            int n = q.size();

            int sum = 0;

            while(n--){
                TreeNode* temp = q.front();
                q.pop();

                sum += temp->val;

                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }

            if(maxSum < sum){
                maxSum = sum;
                level = count;
            }

            count++;
        }

        return level;

    }
};
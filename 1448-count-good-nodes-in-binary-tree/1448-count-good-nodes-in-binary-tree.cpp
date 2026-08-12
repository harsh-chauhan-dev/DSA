/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int dfs(TreeNode* node, int maxValue) {
        if (node == nullptr) {
            return 0;
        }
        int count = 0;
        if (node->val >= maxValue) {
            count = 1;
        }
        maxValue = max(maxValue, node->val);
        count += dfs(node->left, maxValue);
        count += dfs(node->right, maxValue);

        return count;
    }
    int goodNodes(TreeNode* root) { return dfs(root, root->val); }
};
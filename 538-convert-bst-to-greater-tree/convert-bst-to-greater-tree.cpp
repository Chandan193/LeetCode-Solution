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
    void reverseTraversal(TreeNode* node, int& sum) {
        if (node == nullptr) return;
        reverseTraversal(node->right, sum);
        sum += node->val;
        node->val = sum;
        reverseTraversal(node->left, sum);
    }

    TreeNode* convertBST(TreeNode* root) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int sum = 0;
        reverseTraversal(root, sum);
        return root;
    }
};
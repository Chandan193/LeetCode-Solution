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
    void inorder(TreeNode* root, vector<int>& vals) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        if (!root) return;
        inorder(root->left, vals);
        vals.push_back(root->val);
        inorder(root->right, vals);
    }
    
    TreeNode* build(const vector<int>& vals, int l, int r) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        if (l > r) return nullptr;
        int m = l + (r - l) / 2;
        TreeNode* node = new TreeNode(vals[m]);
        node->left = build(vals, l, m - 1);
        node->right = build(vals, m + 1, r);
        return node;
    }

    TreeNode* balanceBST(TreeNode* root) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);

        vector<int> vals;
        inorder(root, vals);
        return build(vals, 0, vals.size() - 1);
    }
};
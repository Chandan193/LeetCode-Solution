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
     void ltr(TreeNode* n, int c) {
        if (!n) return;
        h[n->val] = m;
        m = max(m, c);
        ltr(n->left, c + 1);
        ltr(n->right, c + 1);
    }

    void rtl(TreeNode* n, int c) {
        if (!n) return;
        h[n->val] = max(h[n->val], m);
        m = max(c, m);
        rtl(n->right, c + 1);
        rtl(n->left, c + 1);
    }
    int h[100001], m = 0;
    vector<int> treeQueries(TreeNode* r, vector<int>& q) {
        ltr(r, 0);
        m = 0;
        rtl(r, 0);
        vector<int> res(q.size());
        for (int i = 0; i < q.size(); i++) res[i] = h[q[i]];
        return res;
    }
};
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
   long long kthLargestLevelSum(TreeNode* r, int k) {
    if (!r) return -1;
    vector<long long> s;
    queue<TreeNode*> q;
    q.push(r);
    while (!q.empty()) {
        long long lvlSum = 0, n = q.size();
        for (int i = 0; i < n; ++i) {
            TreeNode* cur = q.front(); q.pop();
            lvlSum += cur->val;
            if (cur->left) q.push(cur->left);
            if (cur->right) q.push(cur->right);
        }
        s.push_back(lvlSum);
    }
    if (s.size() < k) return -1;
    sort(s.begin(), s.end(), greater<>());
    return s[k - 1];
}
};
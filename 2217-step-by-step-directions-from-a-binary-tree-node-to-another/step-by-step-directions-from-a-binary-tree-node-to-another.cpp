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
     bool findP(TreeNode* root, int val, vector<TreeNode*>& path) {
        if (!root) return false;
        path.push_back(root);
        if (root->val == val) return true;
        if (findP(root->left, val, path) || findP(root->right, val, path)) return true;
        path.pop_back();
        return false;
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        vector<TreeNode*> p1, p2;
        findP(root, startValue, p1);
        findP(root, destValue, p2);
        int i = 0;
        while (i < p1.size() && i < p2.size() && p1[i] == p2[i]) i++;
        string res;
        for (int j = i; j < p1.size(); j++) res += 'U';
        for (int j = i; j < p2.size(); j++) res += (p2[j] == p2[j-1]->left ? 'L' : 'R');
        return res;
    }
};
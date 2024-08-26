/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<int> postorder(Node* r) {
    vector<int> res;
    if (!r) return res;
    for (auto c : r->children) {
        auto v = postorder(c);
        res.insert(res.end(), v.begin(), v.end());
    }
    res.push_back(r->val);
    return res;
    }
};
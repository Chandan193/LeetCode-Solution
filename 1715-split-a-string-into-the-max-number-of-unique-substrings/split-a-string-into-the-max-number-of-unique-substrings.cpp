class Solution {
public:
    int dfs(string &s, int i, unordered_set<string> &st) {
    if (i == s.size()) return 0;
    int res = 0;
    for (int j = i + 1; j <= s.size(); ++j) {
        string t = s.substr(i, j - i);
        if (st.find(t) == st.end()) {
            st.insert(t);
            res = max(res, 1 + dfs(s, j, st));
            st.erase(t);
        }
    }
    return res;
    }

    int maxUniqueSplit(string s) {
    unordered_set<string> st;
    return dfs(s, 0, st);
    }
};
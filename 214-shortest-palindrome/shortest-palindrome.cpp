class Solution {
public:
    string shortestPalindrome(string s) {
    string r = s;
    reverse(r.begin(), r.end());
    string t = s + '#' + r;
    int n = t.size();
    vector<int> lps(n, 0);
    for (int i = 1, j = 0; i < n; ++i) {
        while (j > 0 && t[i] != t[j]) j = lps[j - 1];
        if (t[i] == t[j]) j++;
        lps[i] = j;
    }
    return r.substr(0, s.size() - lps[n - 1]) + s;
    }
};
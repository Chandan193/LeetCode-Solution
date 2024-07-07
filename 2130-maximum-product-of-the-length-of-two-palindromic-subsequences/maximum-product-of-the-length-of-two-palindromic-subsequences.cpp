class Solution {
public:
    bool isPalindrome(const string& s) {
    int l = 0, r = s.length() - 1;
    while (l < r) {
        if (s[l] != s[r]) return false;
        l++;
        r--;
    }
    return true;
}

void fn(int i, const string& s, string& t1, string& t2, int& ans) {
    if (i == s.length()) {
        if (!t1.empty() && !t2.empty() && isPalindrome(t1) && isPalindrome(t2)) {
            int temp = t1.length() * t2.length();
            ans = max(ans, temp);
        }
        return;
    }

    t1.push_back(s[i]);
    fn(i + 1, s, t1, t2, ans);
    t1.pop_back();

    t2.push_back(s[i]);
    fn(i + 1, s, t1, t2, ans);
    t2.pop_back();

    fn(i + 1, s, t1, t2, ans);
}

int maxProduct(string s) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int ans = 0;
    string t1, t2;
    fn(0, s, t1, t2, ans);
    return ans;
}

};
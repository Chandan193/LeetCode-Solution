class Solution {
public:
    bool f(string s, int t, int i, int c) {
    if (i == s.length()) {
        return c == t;
    }
    int n = 0;
    for (int j = i; j < s.length(); j++) {
        n = n * 10 + (s[j] - '0');
        if (n + c <= t && f(s, t, j + 1, c + n)) {
            return true;
        }
    }
    return false;
    }

int punishmentNumber(int n) {
    int a = 0;
    for (int i = 1; i <= n; i++) {
        int s = i * i;
        if (f(to_string(s), i, 0, 0)) {
            a += s;
        }
    }
    return a;
}
};
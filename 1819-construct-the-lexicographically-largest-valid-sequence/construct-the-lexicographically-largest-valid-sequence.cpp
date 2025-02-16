class Solution {
public:
    vector<int> constructDistancedSequence(int n) {
    int m = 2 * n - 1;
    vector<int> r(m, 0), v(n + 1, 0);
    function<bool(int)> f = [&](int i) {
        if (i == m) return true;
        if (r[i]) return f(i + 1);
        for (int x = n; x > 0; --x) {
            if (v[x]) continue;
            int j = i + (x > 1 ? x : 0);
            if (j >= m || r[j]) continue;
            r[i] = r[j] = x;
            v[x] = 1;
            if (f(i + 1)) return true;
            r[i] = r[j] = 0;
            v[x] = 0;
        }
        return false;
    };
    f(0);
    return r;
    }
};
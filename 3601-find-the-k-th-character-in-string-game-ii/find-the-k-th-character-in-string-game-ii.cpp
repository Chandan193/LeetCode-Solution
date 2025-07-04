class Solution {
public:
    char kthCharacter(long long k, vector<int>& op) {
    using ll = long long;
    int n = op.size();
    vector<ll> length(n + 1);
    length[0] = 1;

    for (int i = 0; i < n; ++i) {
        if (length[i] > k) {
            length[i + 1] = length[i];
        } else {
            length[i + 1] = length[i] * 2;
        }
    }

    int inc = 0;
    for (int i = n - 1; i >= 0; --i) {
        ll half = length[i];
        if (k > half) {
            k -= half;
            if (op[i] == 1) inc++;
        }
    }

    return ('a' + (inc%26));
    }
};
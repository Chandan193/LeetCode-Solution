class Solution {
public:
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
    const int MOD = 1e9 + 7;
    int n = 26;

    using ll = long long;
    using Matrix = vector<vector<ll>>;

    auto matMul = [&](Matrix& A, Matrix& B) -> Matrix {
        Matrix res(n, vector<ll>(n, 0));
        for (int i = 0; i < n; i++)
            for (int k = 0; k < n; k++)
                if (A[i][k])
                    for (int j = 0; j < n; j++)
                        res[i][j] = (res[i][j] + A[i][k] * B[k][j]) % MOD;
        return res;
    };

    auto matPow = [&](Matrix A, int exp) -> Matrix {
        Matrix res(n, vector<ll>(n, 0));
        for (int i = 0; i < n; i++) res[i][i] = 1;
        while (exp) {
            if (exp % 2) res = matMul(res, A);
            A = matMul(A, A);
            exp /= 2;
        }
        return res;
    };

    Matrix trans(n, vector<ll>(n, 0));
    for (int i = 0; i < 26; i++)
        for (int j = 1; j <= nums[i]; j++)
            trans[(i + j) % 26][i] = (trans[(i + j) % 26][i] + 1) % MOD;

    vector<ll> freq(26, 0);
    for (char c : s)
        freq[c - 'a']++;

    Matrix trans_t = matPow(trans, t);

    vector<ll> result(26, 0);
    for (int i = 0; i < 26; i++)
        for (int j = 0; j < 26; j++)
            result[i] = (result[i] + trans_t[i][j] * freq[j]) % MOD;

    ll total = 0;
    for (int i = 0; i < 26; i++)
        total = (total + result[i]) % MOD;

    return total;
    }
};
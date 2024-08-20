class Solution {
public:
    int stoneGameII(vector<int>& p) {
    int n = p.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    vector<int> s(n + 1);
    for (int i = n - 1; i >= 0; --i) {
        s[i] = s[i + 1] + p[i];
        for (int m = 1; m <= n; ++m) {
            for (int x = 1; x <= 2 * m && i + x <= n; ++x) {
                dp[i][m] = max(dp[i][m], s[i] - dp[i + x][max(m, x)]);
            }
        }
    }
    return dp[0][1]; 
    }
};
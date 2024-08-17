class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
    int m = points.size(), n = points[0].size();
    vector<long long> dp(n), prev(n);

    for (int i = 0; i < n; i++) prev[i] = points[0][i];

    for (int r = 1; r < m; r++) {
        vector<long long> left(n), right(n);
        left[0] = prev[0];
        for (int i = 1; i < n; ++i)
            left[i] = max(left[i - 1] - 1, prev[i]);
        
        right[n - 1] = prev[n - 1];
        for (int i = n - 2; i >= 0; i--)
            right[i] = max(right[i + 1] - 1, prev[i]);
        
        for (int i = 0; i < n; ++i)
            dp[i] = points[r][i] + max(left[i], right[i]);
        
        prev = dp;
    }

    return *max_element(prev.begin(), prev.end());
    }
};
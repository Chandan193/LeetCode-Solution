class Solution {
public:
    int fn(int n, vector<int>& dp){
        if(n==2) return 1;

        if(dp[n]!=-1) return dp[n];

        int maxP = 0;

        for(int i=1; i<n; i++){
            int product = i*(n-i);
            int recProduct = i * fn(n-i, dp);
            maxP = max(maxP, max(product, recProduct));
        }
        return dp[n] = maxP;
    }
    int integerBreak(int n) {
        vector<int> dp(n+1, -1);
        return fn(n, dp);
    }
};
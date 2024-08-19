class Solution {
public:
    int minSteps(int n) {
    if (n == 1) return 0;
    int minStep = 0;
    for (int i = 2; i <= n; ++i) {
        while (n % i == 0) {
            minStep += i;
            n /= i;
        }
    }
    return minStep;
    }
};
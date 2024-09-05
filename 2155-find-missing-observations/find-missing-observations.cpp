class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
    int m = rolls.size();
    int totalSum = mean * (n + m);
    int sum = 0;
    for (int r : rolls) sum += r;
    int missingSum = totalSum - sum;
    
    if (missingSum < n || missingSum > 6 * n) return {};
    
    vector<int> res(n, missingSum / n);
    int rem = missingSum % n;
    
    for (int i = 0; i < rem; i++) res[i]++;
    
    return res;
    }
};
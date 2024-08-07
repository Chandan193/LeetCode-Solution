class Solution {
public:
    const int MOD = 1000000007;
    int sum(const vector<int>& nums, int i, int j) {
    int sum = 0;
    for (int k = i; k <= j; k++) {
        sum += nums[k];
    }
    return sum;
    }

    int rangeSum(vector<int>& nums, int n, int left, int right) {
    vector<int> arr;
    
    for (int i = 0; i < nums.size(); i++) {
        int curr = 0;
        for (int j = i; j < nums.size(); j++) {
            curr += nums[j];
            arr.push_back(curr);
        }
    }

    sort(arr.begin(), arr.end());
    
    long long total = 0;
    for (int i = left - 1; i <= right - 1; i++) {
        total = (total + arr[i]) % MOD;
    }

    return (int)(total);
}
};
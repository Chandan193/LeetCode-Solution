class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
    unordered_map<int, long long> mp;
    long long n = nums.size(), good = 0;

    for (int i = 0; i < n; i++) {
        good += mp[nums[i] - i]++;
    }

    return (n * (n - 1)) / 2 - good;
    }
};
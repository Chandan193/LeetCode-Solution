class Solution {
public:
    int smallestDistancePair(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());  
    int n = nums.size();
    int low = 0, high = nums[n-1] - nums[0];

    auto countPairs = [&](int mid) {
        int count = 0, left = 0;
        for (int right = 0; right < n; right++) {
            while (nums[right] - nums[left] > mid) {
                left++;
            }
            count += right - left;
        }
        return count;
    };

    while (low < high) {
        int mid = low + (high - low) / 2;
        if (countPairs(mid) < k) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }

    return low;
    }
};
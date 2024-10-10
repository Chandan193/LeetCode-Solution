class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
    int n = nums.size();
    vector<int> stk;
    for (int i = 0; i < n; i++) {
        if (stk.empty() || nums[stk.back()] > nums[i]) {
            stk.push_back(i);
        }
    }
    int maxWidth = 0;
    for (int j = n - 1; j >= 0; j--) {
        while (!stk.empty() && nums[j] >= nums[stk.back()]) {
            maxWidth = max(maxWidth, j - stk.back());
            stk.pop_back();
        }
    }
    return maxWidth;
    }
};
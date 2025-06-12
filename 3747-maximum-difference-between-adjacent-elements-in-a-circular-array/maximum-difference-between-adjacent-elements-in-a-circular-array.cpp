class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size();
        int maxd = INT_MIN;
        for(int i=1; i<n; i++){
            maxd = max(maxd, abs(nums[i]-nums[i-1]));
        }
        maxd = max(maxd, abs(nums[0]-nums[n-1]));
        return maxd;
    }
};
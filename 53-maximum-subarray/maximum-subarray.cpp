class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0, maxsum = INT_MIN;
        for(int i : nums){
            sum += i;
            maxsum = max(maxsum, sum);
            if(sum < 0) sum = 0;
        }
        return maxsum;
    }
};
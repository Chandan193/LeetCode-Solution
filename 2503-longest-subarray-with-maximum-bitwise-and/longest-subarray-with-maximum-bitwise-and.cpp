class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxele = *max_element(nums.begin(), nums.end());
        int maxlen = INT_MIN;
        int len = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==maxele){
                len++;
            }
            else {
                len = 0;
            }
            maxlen = max(maxlen, len);
        }
    return maxlen;
    }
};
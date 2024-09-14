class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxele = nums[0];
        for(int x : nums){
            if(x>maxele) maxele = x;
        }
        
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
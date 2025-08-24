class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int prev = 0, curr = 0, maxlen = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i]==1) curr++;
            else{
                maxlen = max(maxlen, (prev+curr));
                prev = curr;
                curr = 0;
            }
        }
        maxlen = max(maxlen, (prev+curr));
        return (maxlen==nums.size()) ? (maxlen-1) : maxlen;
    }
};
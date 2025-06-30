class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> mp;
        for(int i : nums) mp[i]++;
        int maxlen = 0;
        for(int i=0; i<nums.size(); i++){
            int minN = nums[i];
            int maxN = nums[i]+1;
            if(mp.count(maxN)){
                maxlen = max(maxlen, mp[minN] + mp[maxN]);
            }
        }
        return maxlen;
    }
};
class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        vector<int> ans;
        int n = nums.size();
        for(int i=0; i<nums.size(); i++){
            for (int j = max(0, i - k); j <= min(n - 1, i + k); j++) {
            if (nums[j] == key) {
                ans.push_back(i);
                break; 
            }
        }
        }
        return ans;
    }
};
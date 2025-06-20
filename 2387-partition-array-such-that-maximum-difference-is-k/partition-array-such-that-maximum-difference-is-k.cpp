class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int cnt = 0;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int left = 0;
        for(int i=1; i<n; i++){
            if(nums[i] - nums[left] > k){
                cnt++;
                left = i;
            }
        }
        cnt += (nums[n-1] - nums[left] > k) ? ((n-1)-left) : 1;
        return cnt;
    }
};
class Solution {
public:
    int check(vector<int>& nums, int mid){
        int cnt = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] <= mid) cnt++;
        }
        return cnt;
    }
    int findDuplicate(vector<int>& nums) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        int n = nums.size();
        int left = 0, right = n - 1;

        while(left<=right){
            int mid = (left + right)/2;
            if(check(nums, mid) > mid){
                right = mid - 1;
            }
            else{
                left = mid + 1;
            }
        }
        return left;
    }
};
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maj_ele = nums[0], cnt = 1;
        for(int i=1; i<nums.size(); i++){
            if(cnt==0) maj_ele = nums[i];
            if(nums[i] == maj_ele) cnt++;
            else cnt--;
        }
        return maj_ele;
    }
};
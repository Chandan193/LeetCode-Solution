class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        for(int i=1; i<n; i++){
            if(nums[i] == nums[i-1]){
                nums[i-1] = 2 * nums[i-1];
                nums[i] = 0;
            }
        }

        vector<int> ans,t1, t2;

        for(int i=0; i<n; i++){
            if(nums[i] != 0) t1.push_back(nums[i]);
            else t2.push_back(nums[i]);
        }

        for(int i=0; i<t1.size(); i++){
            ans.push_back(t1[i]);
        }

        for(int i=0; i<t2.size(); i++){
            ans.push_back(t2[i]);
        }

        return ans;
    }
};
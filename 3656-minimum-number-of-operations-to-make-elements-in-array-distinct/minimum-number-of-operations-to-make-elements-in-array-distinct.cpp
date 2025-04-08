class Solution {
public:
    int fun(int start, vector<int>& nums, set<int> &st){
        for(int i=start; i<nums.size(); i++){
            st.insert(nums[i]);
        }
        return (st.size()<(nums.size()-start)) ? 1 : 0;
    }
    int minimumOperations(vector<int>& nums) {
        int ans = 0;
        set<int> st;

        for(int i=0; i<nums.size(); i++){
            if(i%3==0){
            st.clear();
            ans += fun(i, nums, st);
            }
        }

        return ans;
    }
};
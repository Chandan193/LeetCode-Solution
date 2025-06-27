class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
       unordered_map<int, int> mpp;
       int n = nums.size();
       for(int i=0; i<n; i++){
          mpp[nums[i]]++;
       }
       vector<int> ans;
       int max_freq = 0;
       for(auto &it : mpp){
          if(it.second > (n/3)){
            max_freq = it.second;
          }
       }

        for(auto &it : mpp){
          if(it.second == max_freq || it.second > (n/3)){
            ans.push_back(it.first);
          }
       }

       return ans;
    }
};
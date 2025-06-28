class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int, int>> temp;

        for(int i=0; i<nums.size(); i++){
            temp.push_back({nums[i], i});
        }

        sort(temp.begin(), temp.end(), [](auto& a, auto& b){
            return a.first > b.first;
        });

        vector<pair<int, int>> arr(temp.begin(), temp.begin()+k);

        sort(arr.begin(), arr.end(), [](auto& a, auto& b){
            return a.second < b.second;
        });

        vector<int> ans;

        for(auto it : arr){
            ans.push_back(it.first);
        }

        return ans;
    }
};
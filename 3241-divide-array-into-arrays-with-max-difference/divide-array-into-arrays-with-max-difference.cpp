class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();

        vector<int> temp;

        for (int i = 0; i < n; i++) {
            temp.push_back(nums[i]);
            if (temp.size() == 3) {
                ans.push_back(temp);
                temp.clear();
            }
        }

        if (ans.size() > 0) {
            for (int i = 0; i < ans.size(); i++) {
                if ((ans[i][2] - ans[i][0]) > k) {
                    ans.clear();
                    break;
                }
            }
        }

        return ans;
    }
};
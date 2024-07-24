class Solution {
public:
    int mapNum(int num, vector<int>& mapping) {
    string numS = to_string(num);
    string ms;
    for (char c : numS) {
        ms += to_string(mapping[c - '0']);
        }
    return stoi(ms);
    }
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        int n = nums.size();
        if(n==1) return {nums[0]};

        vector<pair<int,int>> mp;
        
        for(int i=0; i<n; i++){
            int val = mapNum(nums[i], mapping);
            mp.push_back({val, nums[i]});
        }

        sort(mp.begin(), mp.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        return a.first < b.first;
        });

        vector<int> ans;

        for(auto& it : mp){
            ans.push_back(it.second);
        }

        return ans;
    }
};
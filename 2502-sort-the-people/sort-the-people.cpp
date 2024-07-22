class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);

        int n = names.size();
        map<int, string> mp;
        for(int i=0; i<n; i++){
            mp[heights[i]] = names[i];
        }
        vector<string> ans(n, "");
        int j = n - 1;
        for(auto &it : mp){
            ans[j--] = it.second;
        }
        return ans;
    }
};
class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> mp;
        for(string s : arr){
            mp[s]++;
        }
        vector<string> ans;
        for(int i=0; i<arr.size(); i++){
            if(mp[arr[i]]==1){
                ans.push_back(arr[i]);
            }
        }
        return ans.size()>=k ? ans[k-1] : "";
    }
};
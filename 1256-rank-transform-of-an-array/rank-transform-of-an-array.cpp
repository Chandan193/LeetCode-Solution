class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
       int rank = 0;
       vector<int> temp = arr;
       sort(temp.begin(), temp.end());
        unordered_map<int, int> mp;
        for(int i=0; i<temp.size(); i++){
            if(mp.find(temp[i]) == mp.end()){
                rank++;
                mp[temp[i]] = rank;
            }
        }
        vector<int> ans;

        for(int i=0; i<arr.size(); i++){
            ans.push_back(mp[arr[i]]);
        }

        return ans;
    }
};
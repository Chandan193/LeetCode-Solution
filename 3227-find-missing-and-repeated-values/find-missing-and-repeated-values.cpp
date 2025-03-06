class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n = grid.size();
        int j = 1;
        unordered_map<int, int> mp;
        for(int i=1; i<=n*n; i++){
            mp[i] = 1;
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                mp[grid[i][j]]--;
            }
        }

        int a,b;

        for(auto it : mp){
            if(it.second==-1) a = it.first;
            else if(it.second==1) b = it.first;
        }

        return {a,b};

    }
};
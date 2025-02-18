class Solution {
public:
    unordered_set<string> ans;
    void rec(vector<bool> used, string tiles, string s){
        if(!s.empty()) {ans.insert(s);}

        for(int i=0; i<tiles.size(); i++){
            if(used[i]) continue;
            used[i] = true;
            rec(used, tiles, s + tiles[i]);
            used[i] = false;
        }

    }
    int numTilePossibilities(string tiles) {
        vector<bool> used(tiles.size(), false);
        rec(used, tiles, "");
        // for(string i : ans) cout<<i<<" ";
        return ans.size();
    }
};
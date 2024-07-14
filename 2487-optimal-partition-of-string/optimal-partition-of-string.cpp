class Solution {
public:
    int partitionString(string s) {
        int ans = 0;
        unordered_set<char> seen;
        for(char &c : s){
            if(seen.find(c) != seen.end()){
                ans++;
                seen.clear();
            }
            seen.insert(c);
        }
        return ans+1;
    }
};
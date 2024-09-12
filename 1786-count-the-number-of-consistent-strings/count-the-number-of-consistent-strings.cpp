class Solution {
public:
    bool check(unordered_map<char, int>&mp, string str){
        for(char ch : str){
            if(mp[ch]==0) return false;
        }
        return true;
    }
    int countConsistentStrings(string allowed, vector<string>& words) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        
        unordered_map<char, int> mp;
        for(char ch : allowed){
            mp[ch]++;
        }

        int cnt = 0;

        for(string str : words){
            if(check(mp,str)) cnt++;
        }
    return cnt;
    }
};
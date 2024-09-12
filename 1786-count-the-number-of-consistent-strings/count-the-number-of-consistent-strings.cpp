class Solution {
public:
    bool check(map<char, int>&mp, string str){
        for(char ch : str){
            if(mp[ch]==0) return false;
        }
        return true;
    }
    int countConsistentStrings(string allowed, vector<string>& words) {
        map<char, int> mp;
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
class Solution {
public:
    int possibleStringCount(string word) {
        // unordered_map<char, int> mp;
        // for(char c : word) mp[c]++;
        // int ans = 1;
        // for(auto it : mp){
        //     ans += (it.second - 1);
        // }
        // return ans;
        int ans = 1;
        int cnt = 1;
        for(int i=1; i<word.length(); i++){
            if(word[i]==word[i-1]) cnt++;
            else{
                ans += (cnt - 1);
                cnt = 1;
            }

        }
        if(cnt>0) ans += (cnt - 1);
        return ans;
    }
};
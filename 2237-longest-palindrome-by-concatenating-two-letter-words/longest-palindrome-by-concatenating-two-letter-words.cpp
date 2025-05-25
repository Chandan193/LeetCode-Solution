class Solution {
public:
    int longestPalindrome(vector<string>& words) {
       int ans = 0;
       unordered_map<string, int> mp;
       for(string s : words){
        string r = s;
        reverse(r.begin(), r.end());
        if(mp[r]>0){
            ans += 4;
            mp[r]--;
        }
        else{
            mp[s]++;
        }
       }

       bool flag = false;

       for(auto it : mp){
        string s = it.first;
        if(s[0]==s[1] && it.second>0){
            flag = true;
            break;
        }
       }

       if(flag) ans += 2;

       return ans; 
    }
};
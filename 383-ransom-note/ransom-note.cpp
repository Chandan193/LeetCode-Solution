class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
         ios_base::sync_with_stdio(false);
         cin.tie(NULL);

        map<char, int> mp;
        for(char ch : magazine){
            mp[ch]++;
        }

        for(char ch : ransomNote){
            if(mp[ch] > 0){
                mp[ch]--;
            }
            else{
                return false;
            }
        }
        return true;
    }
};
class Solution {
public:
    int lengthAfterTransformations(string s, int t) {
    const int MOD = 1e9 + 7;
    vector<int> mp(26, 0);
    for(char c : s) mp[c-'a']++;

    while(t>0){
        vector<int> temp(26, 0);
        for(int i=0; i<26; i++){
            char c = i +'a';
            int fq = mp[i];
            if(c=='z'){
                temp['a'-'a'] = (temp['a'-'a'] + fq)%MOD;
                temp['b'-'a'] = (temp['b'-'a'] + fq)%MOD;
            }
            else{
                temp[(c+1)-'a'] = (temp[(c+1)-'a'] + fq)%MOD;
            }
        }
        mp = move(temp); // no copy wiint be there
        t--;
    }

    int ans = 0;

    for(auto it : mp) ans = (ans + it) % MOD;

    return (ans%MOD);
    }
};
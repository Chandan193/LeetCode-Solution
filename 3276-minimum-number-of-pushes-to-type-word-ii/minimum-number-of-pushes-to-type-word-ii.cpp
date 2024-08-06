class Solution {
public:
    int minimumPushes(string word) {
    int freq[26] = {0};
    for(char c : word) 
        freq[c - 'a']++;
        
    sort(freq, freq + 26, greater<int>());

    int push = 1, ans = 0;
    for(int i=0; i < 26 && freq[i] != 0; i++){
        push += (i >= 8 && i % 8 == 0) ? 1 : 0;
        ans += freq[i] * push;    
    }
    
    return ans;
    }
};
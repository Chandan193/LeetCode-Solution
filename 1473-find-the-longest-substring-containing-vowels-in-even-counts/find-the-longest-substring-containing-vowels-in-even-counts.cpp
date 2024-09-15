class Solution {
public:
    int findTheLongestSubstring(string s) {
    unordered_map<string, int> state_map;
    string state = "00000";  
    state_map[state] = -1;  
    int max_len = 0;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'a') state[0] = (state[0] == '0') ? '1' : '0';  
        else if (s[i] == 'e') state[1] = (state[1] == '0') ? '1' : '0';  
        else if (s[i] == 'i') state[2] = (state[2] == '0') ? '1' : '0';  
        else if (s[i] == 'o') state[3] = (state[3] == '0') ? '1' : '0';  
        else if (s[i] == 'u') state[4] = (state[4] == '0') ? '1' : '0'; 

        if (state_map.find(state) != state_map.end()) {
            max_len = max(max_len, i - state_map[state]);
        } else {
            state_map[state] = i;
        }
    }

    return max_len;
    }
};
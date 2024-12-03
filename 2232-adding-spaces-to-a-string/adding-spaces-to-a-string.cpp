class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans = "";
        int j = 0;
        int curr;
        for(int i=0; i<s.size(); i++){
            if(j<spaces.size()) curr = spaces[j];
            if(i==curr){
                ans += ' ';
                ans += s[i];
                j++;
            }
            if(i!=curr){
                ans += s[i];
            }
        }
        return ans;
    }
};
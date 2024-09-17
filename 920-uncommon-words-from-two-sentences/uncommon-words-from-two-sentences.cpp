class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
    unordered_map<string, int> mp1, mp2;
    string t1 = "", t2 = "";
    
    for(int i = 0; i < s1.length(); i++) {
        if(s1[i] != ' ') {
            t1 += s1[i];  
        } else {
            mp1[t1]++;    
            t1 = "";      
        }
    }
    if(t1.length() > 0) mp1[t1]++;  

    for(int i = 0; i < s2.length(); i++) {
        if(s2[i] != ' ') {
            t2 += s2[i];  
        } else {
            mp2[t2]++;    
            t2 = "";      
        }
    }
    if(t2.length() > 0) mp2[t2]++;  

    vector<string> ans;

    for(auto it : mp1) {
        if(it.second == 1 && mp2[it.first] == 0) {
            ans.push_back(it.first);
        }
    }

    for(auto it : mp2) {
        if(it.second == 1 && mp1[it.first] == 0) {
            ans.push_back(it.first);
        }
    }

    return ans;
    }
};
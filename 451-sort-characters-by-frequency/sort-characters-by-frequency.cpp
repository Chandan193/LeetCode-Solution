class Solution {
public:
    string frequencySort(string s) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    unordered_map<char, int> mp;
    for(int i=0; i<s.length(); i++){
        mp[s[i]]++;
    }
    vector<pair<char, int>> freq_vec(mp.begin(), mp.end());
    
    sort(freq_vec.begin(), freq_vec.end(), [](const auto& a, const auto& b) {
        return a.second > b.second;
    });
    
    string result;
    for (const auto& p : freq_vec) {
        result += string(p.second, p.first);
    }
    
    return result;
    }
};
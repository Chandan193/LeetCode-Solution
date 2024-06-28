class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
    vector<int> d(n, 0);
    for (const auto& rd : roads) {
        d[rd[0]]++;
        d[rd[1]]++;
    }
    
    vector<pair<int, int>> cd;
    for (int i = 0; i < n; i++) {
        cd.push_back({d[i], i});
    }
    
    sort(cd.rbegin(), cd.rend());
    
    vector<int> v(n, 0);
    for (int i = 0; i < n; i++) {
        v[cd[i].second] = n - i;
    }
    
    long long t = 0;
    for (const auto& rd : roads) {
        t += v[rd[0]] + v[rd[1]];
    }
    
    return t; 
    }
};
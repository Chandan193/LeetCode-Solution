class Solution {
public:
    string nearestPalindromic(string n) {
    long long num = stoll(n), ans = -1, diff = LLONG_MAX;
    vector<long long> cands;
    int len = n.size();
    
    cands.push_back(pow(10, len) + 1);
    cands.push_back(pow(10, len - 1) - 1);
    
    long long prefix = stoll(n.substr(0, (len + 1) / 2));
    for (int i = -1; i <= 1; i++) {
        string p = to_string(prefix + i);
        string pal = p + string(p.rbegin() + (len & 1), p.rend());
        cands.push_back(stoll(pal));
    }

    for (long long cand : cands) {
        if (cand != num && abs(cand - num) < diff) {
            diff = abs(cand - num);
            ans = cand;
        } else if (abs(cand - num) == diff && cand < ans) {
            ans = cand;
        }
    }
    return to_string(ans); 
    }
};
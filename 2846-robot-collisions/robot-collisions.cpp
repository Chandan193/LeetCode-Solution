class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
    int n = positions.size();
    vector<int> idx(n);
    
    for (int i = 0; i < n; ++i) {
        idx[i] = i;
    }
    
    sort(idx.begin(), idx.end(), [&](int a, int b) {
        return positions[a] < positions[b];
    });
    
    vector<int> stk;  
    vector<bool> s(n, true);  
    
    for (int i = 0; i < n; ++i) {
        int curr = idx[i];
        if (directions[curr] == 'R') {
            stk.push_back(curr);
        } else {
            while (!stk.empty() && healths[curr] > 0) {
                int r = stk.back();
                
                if (healths[r] > healths[curr]) {
                    healths[r]--;
                    s[curr] = false;
                    healths[curr] = 0;
                } else if (healths[r] < healths[curr]) {
                    healths[curr]--;
                    s[r] = false;
                    healths[r] = 0;
                    stk.pop_back();
                } else {
                    s[r] = false;
                    s[curr] = false;
                    healths[r] = 0;
                    healths[curr] = 0;
                    stk.pop_back();
                }
            }
        }
    }
    
    vector<int> ans;
    for (int i = 0; i < n; ++i) {
        if (s[i]) {
            ans.push_back(healths[i]);
        }
    }
    
    return ans;
    }
};
class Solution {
public:
    int numTeams(vector<int>& r) {
    int n = r.size();
    int c = 0;
    
    for (int j = 0; j < n; j++) {
        int ll = 0, gl = 0;
        int lr = 0, gr = 0;
        for (int i = 0; i < j; i++) {
            if (r[i] < r[j]) ll++;
            else if (r[i] > r[j]) gl++;
        }
        for (int k = j + 1; k < n; k++) {
            if (r[k] < r[j]) lr++;
            else if (r[k] > r[j]) gr++;
        }
        c += ll * gr + gl * lr;
    }
    
    return c;
    }
};
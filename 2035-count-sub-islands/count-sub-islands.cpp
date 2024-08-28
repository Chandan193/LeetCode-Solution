class Solution {
public:
    void dfs(vector<vector<int>>& g1, vector<vector<int>>& g2, int i, int j, bool& f) {
    if (i < 0 || j < 0 || i >= g1.size() || j >= g1[0].size() || g2[i][j] == 0) return;
    if (g1[i][j] == 0) f = false;
    g2[i][j] = 0;
    dfs(g1, g2, i+1, j, f);
    dfs(g1, g2, i-1, j, f);
    dfs(g1, g2, i, j+1, f);
    dfs(g1, g2, i, j-1, f);
}

int countSubIslands(vector<vector<int>>& g1, vector<vector<int>>& g2) {
    int c = 0;
    for (int i = 0; i < g1.size(); ++i) {
        for (int j = 0; j < g1[0].size(); ++j) {
            if (g2[i][j] == 1) {
                bool f = true;
                dfs(g1, g2, i, j, f);
                if (f) ++c;
            }
        }
    }
    return c;
}
};
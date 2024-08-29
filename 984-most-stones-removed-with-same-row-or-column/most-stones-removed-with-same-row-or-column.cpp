class Solution {
public:
    void dfs(int i, vector<vector<int>>& stones, unordered_set<int>& visited) {
    visited.insert(i);
    for (int j = 0; j < stones.size(); ++j) {
        if (visited.count(j)) continue;
        if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1]) {
            dfs(j, stones, visited);
        }
    }
    }

int removeStones(vector<vector<int>>& stones) {
    unordered_set<int> visited;
    int n = stones.size(), cnt = 0;
    for (int i = 0; i < n; i++) {
        if (!visited.count(i)) {
            dfs(i, stones, visited);
            cnt++;
        }
    }
    return n - cnt;
    }
};
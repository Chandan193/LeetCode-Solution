class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rc, vector<vector<int>>& cc) {
    auto ts = [](int k, vector<vector<int>>& c) {
        vector<int> in(k, 0), r;
        unordered_map<int, vector<int>> g;
        for (auto& p : c) {
            g[p[0] - 1].push_back(p[1] - 1);
            in[p[1] - 1]++;
        }
        queue<int> q;
        for (int i = 0; i < k; ++i)
            if (in[i] == 0) q.push(i);
        while (!q.empty()) {
            int n = q.front(); q.pop();
            r.push_back(n);
            for (int nb : g[n]) {
                if (--in[nb] == 0) q.push(nb);
            }
        }
        return r.size() == k ? r : vector<int>();
    };

    vector<int> ro = ts(k, rc), co = ts(k, cc);
    if (ro.empty() || co.empty()) return {};

    vector<vector<int>> p(k, vector<int>(2));
    for (int i = 0; i < k; ++i) {
        p[ro[i]][0] = i;
        p[co[i]][1] = i;
    }

    vector<vector<int>> r(k, vector<int>(k, 0));
    for (int i = 0; i < k; ++i) {
        r[p[i][0]][p[i][1]] = i + 1;
    }
    return r;
}
};
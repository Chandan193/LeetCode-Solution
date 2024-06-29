class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<vector<int>> adj(n);
    vector<int> inDeg(n, 0);

    for (const auto& e : edges) {
        adj[e[0]].push_back(e[1]);
        inDeg[e[1]]++;
    }

    queue<int> q;
    for (int i = 0; i < n; ++i) {
        if (inDeg[i] == 0) {
            q.push(i);
        }
    }

    vector<set<int>> anc(n);

    while (!q.empty()) {
        int u = q.front();
        q.pop();

        for (int v : adj[u]) {
            anc[v].insert(u);
            anc[v].insert(anc[u].begin(), anc[u].end());

            if (--inDeg[v] == 0) {
                q.push(v);
            }
        }
    }

    vector<vector<int>> res(n);
    for (int i = 0; i < n; ++i) {
        res[i] = vector<int>(anc[i].begin(), anc[i].end());
    }

    return res;
    }
};
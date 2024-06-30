class UnionFind {
public:
    vector<int> parent;
    vector<int> rank;

    UnionFind(int n) {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int u) {
        if (u != parent[u]) {
            parent[u] = find(parent[u]);
        }
        return parent[u];
    }

    bool unite(int u, int v) {
        int pu = find(u), pv = find(v);
        if (pu == pv) return false;
        if (rank[pu] > rank[pv]) {
            parent[pv] = pu;
        } else if (rank[pu] < rank[pv]) {
            parent[pu] = pv;
        } else {
            parent[pv] = pu;
            rank[pu]++;
        }
        return true;
    }
};

class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        UnionFind uf_alice(n + 1), uf_bob(n + 1);
        int usedEdges = 0;

        for (const auto& edge : edges) {
            if (edge[0] == 3) {
                if (uf_alice.unite(edge[1], edge[2])) {
                    uf_bob.unite(edge[1], edge[2]);
                    ++usedEdges;
                }
            }
        }

        for (const auto& edge : edges) {
            if (edge[0] == 1 && uf_alice.unite(edge[1], edge[2])) {
                ++usedEdges;
            } else if (edge[0] == 2 && uf_bob.unite(edge[1], edge[2])) {
                ++usedEdges;
            }
        }

        for (int i = 1; i <= n; i++){
            if (uf_alice.find(i) != uf_alice.find(1) || uf_bob.find(i) != uf_bob.find(1)) {
                return -1;
            }
        }

        return edges.size() - usedEdges;
    }
};

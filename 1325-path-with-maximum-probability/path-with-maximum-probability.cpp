class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
    vector<vector<pair<int, double>>> g(n);
    for (int i = 0; i < edges.size(); i++) {
        g[edges[i][0]].emplace_back(edges[i][1], succProb[i]);
        g[edges[i][1]].emplace_back(edges[i][0], succProb[i]);
    }

    vector<double> prob(n, 0.0);
    prob[start_node] = 1.0;

    priority_queue<pair<double, int>> pq;
    pq.push({1.0, start_node});

    while (!pq.empty()) {
        auto [p, u] = pq.top();
        pq.pop();

        if (u == end_node) return p;

        for (auto& [v, pr] : g[u]) {
            if (prob[v] < p * pr) {
                prob[v] = p * pr;
                pq.push({prob[v], v});
            }
        }
    }
    
    return 0.0;
    }
};
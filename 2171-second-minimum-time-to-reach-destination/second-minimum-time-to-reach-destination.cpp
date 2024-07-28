class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
    vector<vector<int>> g(n + 1);
    for (const auto& e : edges) {
        g[e[0]].push_back(e[1]);
        g[e[1]].push_back(e[0]);
    }

    deque<pair<int, int>> q;
    q.push_back({1, 1});

    vector<int> dist1(n + 1, -1), dist2(n + 1, -1);
    dist1[1] = 0;

    while (!q.empty()) {
        int x = q.front().first;
        int freq = q.front().second;
        q.pop_front();

        int t = (freq == 1) ? dist1[x] : dist2[x];
        if ((t / change) % 2 == 1) {
            t = change * (t / change + 1) + time;
        } else {
            t += time;
        }

        for (int y : g[x]) {
            if (dist1[y] == -1) {
                dist1[y] = t;
                q.push_back({y, 1});
            } else if (dist2[y] == -1 && dist1[y] != t) {
                if (y == n) {
                    return t;
                }
                dist2[y] = t;
                q.push_back({y, 2});
            }
        }
    }

    return 0;
    }
};
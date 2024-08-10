class Solution {
public:
    int regionsBySlashes(vector<string>& grid) {
    int n = grid.size();
    vector<vector<int>> g(n * 3, vector<int>(n * 3, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == '/') {
                g[i * 3][j * 3 + 2] = g[i * 3 + 1][j * 3 + 1] = g[i * 3 + 2][j * 3] = 1;
            } else if (grid[i][j] == '\\') {
                g[i * 3][j * 3] = g[i * 3 + 1][j * 3 + 1] = g[i * 3 + 2][j * 3 + 2] = 1;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n * 3; i++) {
        for (int j = 0; j < n * 3; j++) {
            if (g[i][j] == 0) {
                ++ans;
                queue<pair<int, int>> q;
                q.push({i, j});
                g[i][j] = 1;
                while (!q.empty()) {
                    auto [x, y] = q.front(); q.pop();
                    for (auto [dx, dy] : vector<pair<int, int>>{{1, 0}, {-1, 0}, {0, 1}, {0, -1}}) {
                        int nx = x + dx, ny = y + dy;
                        if (nx >= 0 && nx < n * 3 && ny >= 0 && ny < n * 3 && g[nx][ny] == 0) {
                            g[nx][ny] = 1;
                            q.push({nx, ny});
                        }
                    }
                }
            }
        }
    }
    return ans;
        
    }
};
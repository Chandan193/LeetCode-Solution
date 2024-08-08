class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
         vector<vector<int>> res;
    int total = rows * cols, x = rStart, y = cStart;
    res.push_back({x, y});
    int dx = 0, dy = 1, len = 1;
    
    while (res.size() < total) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < len; j++) {
                x += dx;
                y += dy;
                if (x >= 0 && x < rows && y >= 0 && y < cols)
                    res.push_back({x, y});
            }
            swap(dx, dy);
            dy = -dy;
        }
        len++;
    }
    return res;
    }
};
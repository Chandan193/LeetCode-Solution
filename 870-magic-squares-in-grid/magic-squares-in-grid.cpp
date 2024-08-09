class Solution {
public:
    bool check(int i, int j, vector<vector<int>>& grid) {
    if (i + 2 >= grid.size() || j + 2 >= grid[0].size()) return false;

    if (grid[i][j] == 4 && grid[i + 1][j + 1] == 5 && grid[i + 2][j + 2] == 6) {
        if ((grid[i][j + 1] == 3 && grid[i][j + 2] == 8 && grid[i + 1][j] == 9 && grid[i + 1][j + 2] == 1 && 
             grid[i + 2][j] == 2 && grid[i + 2][j + 1] == 7) ||
            (grid[i][j + 1] == 9 && grid[i][j + 2] == 2 && grid[i + 1][j] == 3 && grid[i + 1][j + 2] == 7 &&
             grid[i + 2][j] == 8 && grid[i + 2][j + 1] == 1)) {
            return true;
        }
    } else if (grid[i][j] == 6 && grid[i + 1][j + 1] == 5 && grid[i + 2][j + 2] == 4) {
        if ((grid[i][j + 1] == 7 && grid[i][j + 2] == 2 && grid[i + 1][j] == 1 && grid[i + 1][j + 2] == 9 &&
             grid[i + 2][j] == 8 && grid[i + 2][j + 1] == 3) ||
            (grid[i][j + 1] == 1 && grid[i][j + 2] == 8 && grid[i + 1][j] == 7 && grid[i + 1][j + 2] == 3 &&
             grid[i + 2][j] == 2 && grid[i + 2][j + 1] == 9)) {
            return true;
        }
    } else if (grid[i][j + 2] == 4 && grid[i + 1][j + 1] == 5 && grid[i + 2][j] == 6) {
        if ((grid[i][j + 1] == 3 && grid[i][j] == 8 && grid[i + 1][j] == 1 && grid[i + 1][j + 2] == 9 &&
             grid[i + 2][j + 1] == 7 && grid[i + 2][j + 2] == 2) ||
            (grid[i][j + 1] == 9 && grid[i][j] == 2 && grid[i + 1][j] == 7 && grid[i + 1][j + 2] == 3 &&
             grid[i + 2][j + 1] == 1 && grid[i + 2][j + 2] == 8)) {
            return true;
        }
    } else if (grid[i][j + 2] == 6 && grid[i + 1][j + 1] == 5 && grid[i + 2][j] == 4) {
        if ((grid[i][j + 1] == 7 && grid[i][j] == 2 && grid[i + 1][j] == 9 && grid[i + 1][j + 2] == 1 &&
             grid[i + 2][j + 1] == 3 && grid[i + 2][j + 2] == 8) ||
            (grid[i][j + 1] == 1 && grid[i][j] == 8 && grid[i + 1][j] == 3 && grid[i + 1][j + 2] == 7 &&
             grid[i + 2][j + 1] == 9 && grid[i + 2][j + 2] == 2)) {
            return true;
        }
    }

    return false;
}

    int numMagicSquaresInside(vector<vector<int>>& grid) {
       if(grid.size()<3 || grid[0].size()<3) return 0;

       int row = grid.size();
       int col = grid[0].size();

       int cnt = 0;

       for(int i=0; i<=row-3; i++){
        for(int j=0; j<=col-3; j++){
            cnt += check(i, j, grid);
        }
       }

       return cnt;
    }
};
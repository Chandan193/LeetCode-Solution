class Solution {
public:
    Solution(){
         ios_base::sync_with_stdio(false);
         cin.tie(NULL);
         cout.tie(NULL);
    }
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<int> mRow(m, INT_MAX);
        vector<int> mCol(n, INT_MIN);

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                mRow[i] = min(mRow[i], matrix[i][j]);
            }
        }

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                mCol[j] = max(mCol[j], matrix[i][j]);
            }
        }

        vector<int> ans;

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j]==mRow[i] && matrix[i][j]==mCol[j]){
                    ans.push_back(matrix[i][j]);
                }
            }
        }
    return ans;
    }
};
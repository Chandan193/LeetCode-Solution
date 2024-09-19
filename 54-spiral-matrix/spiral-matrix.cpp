class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int row = matrix.size();
        int col = matrix[0].size();
        int top = 0, left = 0, bottom = row - 1, right = col - 1;
        int direction = 0;

        while(top<=bottom && left<=right){
            switch(direction){
                case 0:
                    for(int i=left; i<=right; i++){
                        ans.push_back(matrix[top][i]);
                    }
                    top++;
                    break;
                case 1:
                    for(int i=top; i<=bottom; i++){
                        ans.push_back(matrix[i][right]);
                    }
                    right--;
                    break;
                case 2:
                    for(int i=right; i>=left; i--){
                        ans.push_back(matrix[bottom][i]);
                    }
                    bottom--;
                    break;
                case 3:
                    for(int i=bottom; i>=top; i--){
                        ans.push_back(matrix[i][left]);
                    }
                    left++;
                    break;
            }
            direction = (direction+1)%4;
        }

        return ans;
    }
};
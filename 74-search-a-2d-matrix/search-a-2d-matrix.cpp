class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        vector<int> arr;
        for(int i=0; i<matrix.size(); i++){
            for(int j=0; j<matrix[0].size(); j++){
                arr.push_back(matrix[i][j]);
            }
        }

        int left = 0, right = arr.size() - 1;
        while(left <= right){
            int mid = (left + right)/2;
            if(arr[mid] > target){
                right = mid - 1;
            }
            else if(arr[mid] < target){
                left = mid + 1;
            }
            else{
                return true;
            }
        }

        return false;
    }
};
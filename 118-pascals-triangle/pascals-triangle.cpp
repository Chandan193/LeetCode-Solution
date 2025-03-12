class Solution {
public:
    vector<int> genRow(int n){
        long long ans = 1;
        vector<int> v;
        v.push_back(1);
        for(int i=1; i<n; i++){
            ans = ans * (n - i);
            ans = ans / i;
            v.push_back(ans);
        }
        return v;
    }
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans;

        for(int i=1; i<=numRows; i++){
            vector<int> temp = genRow(i);
            ans.push_back(temp);
        }

        return ans;
    }
};
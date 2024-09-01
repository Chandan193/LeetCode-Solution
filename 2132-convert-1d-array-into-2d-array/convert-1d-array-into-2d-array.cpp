class Solution {
public:
    vector<int> ins(vector<int>& o, int start, int end){
        vector<int> temp;
        for(int i=start; i<end; i++){
            temp.push_back(o[i]);
        }
        return temp;
    }
    vector<vector<int>> construct2DArray(vector<int>& o, int m, int n) {
        int size = o.size();
        if(m*n!= size) return {};

        vector<vector<int>> ans;

        int start = 0, end = n;

        int p1 = 0, p2 = 1;

        for(int i=0; i<m; i++){
            start = p1*n;
            end = p2*n;

            p1 += 1;
            p2 += 1;

            ans.push_back(ins(o, start, end));
        }
        return ans;
    }
};
class Solution {
public:
    vector<vector<int>> ans;
    void comb(int idx, vector<int>& candidates, vector<int> temp, int target){
        if(target==0){
            ans.push_back(temp);
            return;
        }

       for(int i=idx; i<candidates.size(); i++){
            if(i>idx && candidates[i]==candidates[i-1]) continue;
            if(candidates[i] > target) break;
            temp.push_back(candidates[i]);
            comb(i+1, candidates, temp, target - candidates[i]);
            temp.pop_back();
       }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> temp;

        sort(candidates.begin(), candidates.end());
        
        comb(0, candidates, temp, target);

        return ans;
    }
};
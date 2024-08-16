class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
    int n = arrays.size();
    int min_val = arrays[0][0];
    int max_val = arrays[0].back();
    int maxD = 0;

    for (int i = 1; i < n; i++) {
        maxD = max(maxD, abs(arrays[i].back() - min_val));
        maxD = max(maxD, abs(arrays[i][0] - max_val));
        min_val = min(min_val, arrays[i][0]);
        max_val = max(max_val, arrays[i].back());
    }

    return maxD;
    }
};
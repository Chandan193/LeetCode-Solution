class Solution {
public:
    int largestCombination(vector<int>& c) {
    int res = 0;
    for (int i = 0; i < 24; ++i) {
        int cnt = 0;
        for (int x : c) cnt += (x >> i) & 1;
        res = max(res, cnt);
    }
    return res;
    }
};
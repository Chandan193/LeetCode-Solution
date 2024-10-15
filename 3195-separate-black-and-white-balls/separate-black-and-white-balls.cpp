class Solution {
public:
    long long minimumSteps(string s) {
    long long c = 0, r = 0;
    for (char x : s) {
        if (x == '1') r++;
        else c += r;
    }
    return c;
    }
};
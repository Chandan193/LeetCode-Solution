class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.size();
    int count = 0;
    long long val = 0, base = 1;
    
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == '0') {
            count++;
        } else {
            if (base <= k && val + base <= k) {
                val += base;
                count++;
            }
        }
        if (base <= k) base <<= 1;
    }
    
    return count;
    }
};
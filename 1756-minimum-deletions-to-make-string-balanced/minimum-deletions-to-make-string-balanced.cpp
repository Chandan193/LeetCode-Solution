class Solution {
public:
    int minimumDeletions(string s) {
    int a = 0, b = 0, ans = s.size();
    for (char c : s) if (c == 'a') a++;
    for (char c : s) {
        if (c == 'a') a--;
        ans = min(ans, a + b);
        if (c == 'b') b++;
    }
    return ans; 
    }
};
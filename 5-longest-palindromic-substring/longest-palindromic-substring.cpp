class Solution {
public:
    string longestPalindrome(string s) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n = s.length();
    if (n == 0) return "";

    int start = 0, maxLen = 1;

    for (int i = 0; i < n; i++) {
        int left = i, right = i;
        while (left >= 0 && right < n && s[left] == s[right]) {
            int len = right - left + 1;
            if (len > maxLen) {
                maxLen = len;
                start = left;
            }
            left--;
            right++;
        }

        left = i, right = i + 1;
        while (left >= 0 && right < n && s[left] == s[right]) {
            int len = right - left + 1;
            if (len > maxLen) {
                maxLen = len;
                start = left;
            }
            left--;
            right++;
        }
    }

    string ans = "";
    for (int i = start; i < start + maxLen; i++) {
        ans += s[i];
    }
    
    return ans;
       
       
    }
};
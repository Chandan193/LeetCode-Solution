class Solution {
public:
    int maximumGain(string s, int x, int y) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int score = 0;

    if (x > y) {
        stack<char> stk;
        for (char c : s) {
            if (!stk.empty() && stk.top() == 'a' && c == 'b') {
                stk.pop();
                score += x;
            } else {
                stk.push(c);
            }
        }

        string rem;
        while (!stk.empty()) {
            rem += stk.top();
            stk.pop();
        }
        reverse(rem.begin(), rem.end());

        for (char c : rem) {
            if (!stk.empty() && stk.top() == 'b' && c == 'a') {
                stk.pop();
                score += y;
            } else {
                stk.push(c);
            }
        }
    } else {
        stack<char> stk;
        for (char c : s) {
            if (!stk.empty() && stk.top() == 'b' && c == 'a') {
                stk.pop();
                score += y;
            } else {
                stk.push(c);
            }
        }

        string rem;
        while (!stk.empty()) {
            rem += stk.top();
            stk.pop();
        }
        reverse(rem.begin(), rem.end());

        for (char c : rem) {
            if (!stk.empty() && stk.top() == 'a' && c == 'b') {
                stk.pop();
                score += x;
            } else {
                stk.push(c);
            }
        }
    }

    return score;
    }
};
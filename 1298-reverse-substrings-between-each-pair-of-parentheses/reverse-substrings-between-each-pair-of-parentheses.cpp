class Solution {
public:
    string reverseParentheses(string s) {
        string ans = "";
        stack<string> stk;
        for(char c : s){
           if(c == '('){
            stk.push(ans);
            ans = "";
           }
           else if(c == ')'){
            reverse(ans.begin(), ans.end());
            ans = stk.top() + ans;
            stk.pop();
           }
           else{
            ans += c;
           }

        }
        return ans;
    }
};
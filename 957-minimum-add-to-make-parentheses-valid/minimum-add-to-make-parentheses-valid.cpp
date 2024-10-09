class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> stk;
        for(char c : s){
           if(stk.empty() || c=='(' || (c==')' && stk.top()==')')){
            stk.push(c);
           }
           if(c==')' && stk.top()=='('){
            stk.pop();
           }
        }

        return stk.size();
    }
};
class Solution {
public:
    int minLength(string s) {
      stack<char> stk;
      for(int i=0; i<s.length(); i++){
        char curr = s[i];
        if(stk.empty()){
            stk.push(curr);
            continue;
        }
        if(curr=='B' && stk.top()=='A') stk.pop();
        else if(curr=='D' && stk.top()=='C') stk.pop();
        else stk.push(curr);
      }
      return stk.size();  
    }
};
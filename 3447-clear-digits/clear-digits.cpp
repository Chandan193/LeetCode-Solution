class Solution {
public:
    string clearDigits(string s) {

       stack<char> stk;

       for(int i=0; i<s.length(); i++){
        if(s[i]>='a' && s[i]<='z'){
            stk.push(s[i]);
        }
        else{
            if(!stk.empty()) stk.pop();
        }
       }

       string ans = "";
       while(!stk.empty()){
        ans = stk.top() + ans;
        stk.pop();
       }
        
        return ans;
    }
};
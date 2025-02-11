class Solution {
public:
    string removeOccurrences(string s, string part) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);


        stack<char> stk;
        int n = part.length();
        for(int i=0; i<s.length(); i++){
            stk.push(s[i]);
            if(stk.size()>=n){
                string temp = "";
                for(int i=0; i<n; i++){
                    if(!stk.empty()) temp = stk.top() + temp, stk.pop();
                }
                if(temp != part){
                    for(char c : temp){
                        stk.push(c);
                    }
                }
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
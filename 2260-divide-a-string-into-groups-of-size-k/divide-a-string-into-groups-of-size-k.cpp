class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        string temp = "";

        for(int i=0; i<s.length(); i++){
            temp += s[i];
            if(temp.length()==k){
                cout<<temp<<endl;
                ans.push_back(temp);
                temp = "";
            }
        }

        int n = temp.length();
        if(temp.length()>=1){
        for(int i=0; i<(k-n); i++){
            temp += fill;
        }
        }

        if(temp.length()==k) ans.push_back(temp);

        return ans;
    }
};
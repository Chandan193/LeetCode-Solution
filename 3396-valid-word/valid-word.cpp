class Solution {
public:
    bool isValid(string word) {
       if(word.length()<3) return false;
       int v = 0, c = 0, d = 0;
       unordered_set<char> st = {'a','e','i','o','u','A','E','I','O','U'};
       for(char x : word){
        if((x>='a' && x<='z') || (x>='A' && x<='Z')){
            if(st.find(x)!=st.end()) v++;
            else c++;
        }
        else if(x>='0' && x<='9') d++;
        else return false;
       }
       return (v>=1 && c>=1 && (v+c+d)==word.size());
    }
};
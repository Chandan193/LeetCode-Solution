class Solution {
public:
    char kthCharacter(int k) {
        string word = "a";
        string temp = "";
        while(word.length() < k){
            for(int i=0; i<word.length(); i++){
                temp += (word[i]+1);
            }
            word = word+temp;
            // cout<<word<<" ";
            temp = "";
        }
        return word[k-1];
    }
};
class Solution {
public:
    bool isCircularSentence(string s) {
        string temp = "";
        vector<string> arr;
        for(char c : s){
            if(c!=' ')temp += c;
            if(c==' '){
                arr.push_back(temp);
                temp = "";
            }
        }

        if(temp.length()>0) arr.push_back(temp);

        if(arr.size()==1){
            string t = arr[0];
            if(t[0] == t.back()) return true;
            else return false;
        }

        string t1 = arr[0];
        string t2 = arr.back();

        if(t1[0] != t2.back()) return false;

        for(int i=1; i<arr.size(); i++){
            string t1 = arr[i];
            string t2 = arr[i-1];
            if(t1[0] != t2.back()) return false;
        }

        return true;
    }
};
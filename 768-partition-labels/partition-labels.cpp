class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char, int> mpp;
        for(int i=0;i<s.length();i++){
            mpp[s[i]] = i;
        }
        
        vector<int> result;
        
        int start = 0, end = 0;
        for(int i=0;i<s.length();i++){
            end = max(end, mpp[s[i]]);
            if(i==end){
                result.push_back(end - start + 1);
                start = end + 1;
            }
        }
        return result;
    }
};
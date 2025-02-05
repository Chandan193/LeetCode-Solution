class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int cnt = 0;
        string t1, t2;
        for(int i=0; i<s1.length(); i++){
            if(s1[i] != s2[i]){
            cnt++;
            t1 += s1[i];
            t2 += s2[i];
            }
            if(cnt>2) break;
        }
        reverse(t1.begin(), t1.end());
        return (cnt<=2 && t1==t2);
    }
};
class Solution {
public:
    int findLucky(vector<int>& arr) {
       int ln = -1;
       vector<int> freq(501, 0);
       for(int i : arr) freq[i]++;
       for(int it : arr) ln = (it == freq[it]) ? max(ln, it) : ln;
       return ln;
    }
};
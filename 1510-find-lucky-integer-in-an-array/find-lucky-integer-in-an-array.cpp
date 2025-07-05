class Solution {
public:
    int findLucky(vector<int>& arr) {
       int ln = -1;
       unordered_map<int, int> mp;
       for(int i : arr) mp[i]++;
       for(auto it : mp){
            ln = (it.first == it.second) ? max(ln, it.first) : ln;
       } 
       return ln;
    }
};
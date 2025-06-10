class Solution {
public:
    int maxDifference(string s) {
        map<char, int> mp;
        for(char c : s){
            mp[c]++;
        }
        int maxodd = INT_MIN, mineven = INT_MAX;
        
        for(auto it : mp){
            if(it.second % 2 != 0){
                maxodd = max(maxodd, it.second);
            }
            if(it.second % 2 == 0){
                mineven = min(mineven, it.second);
            }
        }


        return (maxodd - mineven);
    }
};
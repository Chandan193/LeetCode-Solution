class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> mp;
        unordered_set<int> st;
        vector<int> ans;
        
        for(const auto& q : queries){
            int ball = q[0];
            int color = q[1];
            
            if(mp.find(ball) != mp.end()){
                int prev = mp[ball];
                bool remove = true;
                
                for(const auto& it : mp){
                    if(it.second == prev && it.first != ball){
                        remove = false;
                        break;
                    }
                }
                if(remove){
                    st.erase(prev);
                }
            }
            
            mp[ball] = color;
            st.insert(color);
            
            ans.push_back(st.size());
        }
        
        return ans;
    }
};
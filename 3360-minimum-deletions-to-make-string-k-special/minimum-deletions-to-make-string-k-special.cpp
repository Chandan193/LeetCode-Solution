class Solution {
public:
    int minimumDeletions(string word, int k) {
        map<char, int> mp;
        for(char c : word) mp[c]++;
        vector<int> freq;
        for(auto it : mp) freq.push_back(it.second);
        sort(freq.begin(), freq.end());
        int ans = INT_MAX, n = freq.size();
        for(int i=0; i<n; i++){
            int t = freq[i], d = 0;
            for(int j=0; j<n; j++){
                if(freq[j] < t) d += freq[j];
                else if(freq[j] > t+k) d += freq[j] - (t+k);
            }
            ans = min(ans, d);
        }
        return ans;
    }
};
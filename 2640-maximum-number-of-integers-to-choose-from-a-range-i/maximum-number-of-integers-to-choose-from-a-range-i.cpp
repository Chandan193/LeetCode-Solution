class Solution {
public:
    int maxCount(vector<int>& banned, int n, int maxSum) {
        unordered_map<int, int> mp;
        for(int x : banned) mp[x]++;
        int cnt = 0;
        int sum = 0;
        for(int i=1; i<=n; i++){
            if(mp.find(i)==mp.end()){
                if(maxSum>=sum+i){
                    sum += i;
                    cnt++;
                }
            }
            else{
                continue;
            }
        }
        return cnt;
    }
};
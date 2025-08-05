class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = baskets.size();
        vector<int> avail(n, 1);
        for(int i=0; i<fruits.size(); i++){
            int f = fruits[i];
            for(int j=0; j<n; j++){
                if(baskets[j]>=f && avail[j]==1){
                    avail[j] = 0;
                    break;
                }
            }
        }

        int cnt = 0;

        for(int x : avail) cnt += (x==1) ? 1 : 0;

        return cnt;
    }
};
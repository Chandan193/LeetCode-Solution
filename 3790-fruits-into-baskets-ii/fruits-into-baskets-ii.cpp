class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = baskets.size();
        vector<int> avail(n, 1);
        int cnt = 0;
        for(int i=0; i<fruits.size(); i++){
            int f = fruits[i];
            for(int j=0; j<n; j++){
                if(baskets[j]>=f && avail[j]==1){
                    avail[j] = 0;
                    cnt++;
                    break;
                }
            }
        }


        return (avail.size()-cnt);
    }
};
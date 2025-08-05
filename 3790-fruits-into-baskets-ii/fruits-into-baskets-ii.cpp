class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int cnt = 0;
        for(int i=0; i<fruits.size(); i++){
            int f = fruits[i];
            for(int j=0; j<baskets.size(); j++){
                if(baskets[j]!=0 && baskets[j]>=f){
                    baskets[j] = 0;
                    cnt++;
                    break;
                }
            }
        }
        return (baskets.size()-cnt);
    }
};
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi = 0;
        int s = prices[0];
        for(int i=1; i<prices.size(); i++){
            if(s < prices[i]){
                maxi += prices[i] - s;
            }
            s = prices[i];
        }
        return maxi;
    }
};
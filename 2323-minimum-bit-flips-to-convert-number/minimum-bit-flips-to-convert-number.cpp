class Solution {
public:
    int minBitFlips(int start, int goal) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int xorr = start ^ goal;
        int cnt = 0;
        for(int i=0; i<31; i++){
            if(xorr & (1 << i)){
                cnt++;
            }
        }
        return cnt;
    }
};
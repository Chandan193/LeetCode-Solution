class Solution {
public:
    int findComplement(int num) {
        if(num==0) return 1;
        int len = 0;
        int temp = num;
        while(temp>0){
            len++;
            temp >>= 1;
        }
        int cnt = 0;
        for(int i=0; i<len; i++){
            cnt = (cnt << 1) | 1;
        }
        return num^cnt;
    }
};
class Solution {
public:
    int passThePillow(int n, int time) {
        int dir = 1;
        int pos = 1;
        while(time){
            pos += dir;
            if(pos==n) dir = -1;
            else if(pos==1) dir = 1;
            time--;
        }

        return pos;
    }
};
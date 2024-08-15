class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;
        for(int num : bills){
            five += (num==5) ? 1 : 0;
            if(num == 10){
                if(five==0){
                    return false;
                }
                five--;
                ten++;
            }
            else if(num==20){
                if(five>0 && ten>0){
                    five--;
                    ten--;
                } else if(five>=3){
                    five -= 3;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};
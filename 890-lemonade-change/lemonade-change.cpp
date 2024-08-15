class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        if(bills[0]>5) return false;

        int five = 0, ten = 0;

        for(int num : bills){
            if(num == 5){
                five++;
            }
            else if(num == 10){
                if(five>0){
                    five--;
                }else{
                    return false;
                }
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
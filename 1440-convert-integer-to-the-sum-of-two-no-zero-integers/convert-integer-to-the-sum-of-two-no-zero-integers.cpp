class Solution {
public:
    bool check(int x){
        while(x>0){
            if(x%10==0) return false;
            x/=10;
        }
        return true;
    }
    vector<int> getNoZeroIntegers(int n) {
        int a=1, b=n-1;
        if(check(b)){
                return {a,b};
        }
        while(check(b)==false){
            b--;
            a++;
        }
        if(check(a) && check(b)) return{a,b};
        while(check(a)==false){
            a++;
            b--;
        }
        if(check(a) && check(b)) return{a,b};
        return {1,1};
    }
};
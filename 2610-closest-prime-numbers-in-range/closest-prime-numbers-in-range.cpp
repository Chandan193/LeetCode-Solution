class Solution {
public:
    bool checkPrime(int n){
        if(n==1) return false;
        for(int i=2; i<=sqrt(n); i++){
            if(n%i==0) return false;
        }
        return true;
    }
    vector<int> closestPrimes(int left, int right) {
    int num1=-1, num2=-1;
    vector<int> v;

    for(int i=left; i<=right; i++){
        if(checkPrime(i)) v.push_back(i);
    }

    int mindiff = INT_MAX;

    for(int i=1; i<v.size(); i++){
        int diff = v[i] - v[i-1];
        if(diff < mindiff){
            num1 = v[i-1];
            num2 = v[i];
            mindiff = diff;
        }
    }

    return {num1, num2};
    }
};
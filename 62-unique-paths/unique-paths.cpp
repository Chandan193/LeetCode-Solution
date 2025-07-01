class Solution {
public:
    int nCr(int n, int r){
        double ans = 1;
        for(int i=0; i<r; i++){
            ans *= (n-i);
            ans /= (i+1);
        }
        return (int)ans;
    }
    int uniquePaths(int m, int n) {
        int N = (m+n)-2;
        int r = min(m, n)-1;
        return nCr(N, r);
    }
};
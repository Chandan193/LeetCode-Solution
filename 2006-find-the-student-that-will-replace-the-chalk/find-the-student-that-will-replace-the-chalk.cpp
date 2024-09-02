class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        if(n==1 && chalk[0]<=k) return (chalk[0]/k);
        long long sum = 0;
        for(int ch : chalk) sum += ch;
        k %= sum;
        for(int i=0; i<n; i++){
            if(k<chalk[i]) return i;
            else k -= chalk[i];
        }
        return -1;
    }
};
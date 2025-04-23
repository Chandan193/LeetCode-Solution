class Solution {
public:
    int digSum(int x){
        int sum = 0;
        while(x>0){
            sum += x%10;
            x /= 10;
        }
        return sum;
    }
    int countLargestGroup(int n) {
        int ans = 0;
        vector<int> arr(n+1, 0);
        for(int i=1; i<=n; i++){
            arr[digSum(i)]++;
        }
        
        int maxele = INT_MIN;

        for(int i : arr){
            maxele = max(maxele, i);
        }

        for(int i : arr){
            ans += (i==maxele) ? 1 : 0;
        }

        return ans;
    }
};
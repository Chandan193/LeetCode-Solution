class Solution {
public:
    int digSum(int n){
        int sum = 0;
        while(n>0){
            sum += n%10;
            n /= 10;
        }
        return sum;

    }
    int maximumSum(vector<int>& nums) {
        unordered_map<int, int> mp;
        int maxi = -1;

        for (int num : nums) {
            int sum = digSum(num);
            if (mp.count(sum)) {
                maxi = max(maxi, mp[sum] + num);
                mp[sum] = max(mp[sum], num);
            } else {
                mp[sum] = num;
            }
        }
        return maxi;
    }
};
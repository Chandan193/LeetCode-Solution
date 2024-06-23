class Solution {
public:
    double minimumAverage(vector<int>& nums) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
        int n = nums.size();
        vector<double> avg;
        sort(nums.begin(), nums.end());
        for(int i=0; i<n/2; i++){
            avg.push_back((double)(nums[i] + nums[n-1-i])/2);
        }
        sort(avg.begin(), avg.end());
        return avg[0];
    }
};
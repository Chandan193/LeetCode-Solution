class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0) return 0;
        sort(nums.begin(), nums.end());
        int cnt = 1;
        int maxcnt = 1;
        bool flag = false;
        for(int i=1; i<nums.size(); i++){
            if((nums[i]-nums[i-1])==1) cnt++;
            else if(nums[i]==nums[i-1]){
                while(nums[i]!=nums[i-1]){ 
                flag = true;
                i++;
                }
            }
            else cnt = 1;
            maxcnt = (flag==true) ? max(maxcnt, cnt+1) : max(maxcnt, cnt);
        }
        return maxcnt;
    }
};
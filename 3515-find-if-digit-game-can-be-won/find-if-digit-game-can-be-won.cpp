class Solution {
public:
    bool canAliceWin(vector<int>& nums) {
      int sd = 0, dd = 0;
      for(int n : nums){
        if(n<=9) sd += n;
        else dd += n;
      }  
      return (sd>dd) || (sd<dd);
    }
};
class Solution {
public:
    string triangleType(vector<int>& nums) {
        int x = nums[0], y = nums[1], z = nums[2];
        if((x+y>z && y+z>x && x+z>y)){
        if(x==y && y==z && z==x) return "equilateral";
        else if(x!=y && y!=z && z!=x) return "scalene";
        else if(x==y || y!=z || z!=x) return "isosceles";
        }
        return "none";
    }
};
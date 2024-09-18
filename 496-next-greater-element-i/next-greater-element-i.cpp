class Solution {
public:
    int findele(vector<int>& nums2, int ele){
        for(int i=0; i<nums2.size(); i++){
            if(nums2[i]==ele){
                for(int j=i+1; j<nums2.size(); j++){
                    if(nums2[j]>ele) return nums2[j];
                    }
                }
        }
        return -1;
    }
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        for(int i=0; i<nums1.size(); i++){
            ans.push_back(findele(nums2, nums1[i]));
        }
        return ans;
    }
};
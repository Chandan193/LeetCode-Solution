class FindSumPairs {
    vector<int> a, b;
    unordered_map<int, int> m;
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) : a(nums1), b(nums2) {
         for (int x : b) m[x]++;
    }
    
    void add(int i, int v) {
        m[b[i]]--;
        b[i] += v;
        m[b[i]]++;
    }
    
    int count(int t) {
      int c = 0;
        for (int x : a) {
            c += m[t - x];
        }
        return c;
    }
};

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
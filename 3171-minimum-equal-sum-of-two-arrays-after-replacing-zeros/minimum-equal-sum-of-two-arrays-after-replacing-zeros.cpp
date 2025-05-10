
class Solution {
public:
    using ll = long long;
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
    ll sum1 = 0, sum2 = 0;
    int z1 = 0, z2 = 0;

    for (int i : nums1) {
        if (i == 0) z1++;
        else sum1 += i;
    }

    for (int i : nums2) {
        if (i == 0) z2++;
        else sum2 += i;
    }

    if (z1 == 0 && z2 == 0 && sum1 != sum2)
        return -1;

    ll base1 = sum1 + z1;
    ll base2 = sum2 + z2;

    if (base1 > base2) {
        ll diff = base1 - base2;
        if (z2 == 0)
            return -1;
        return base1;
    } else if (base2 > base1) {
        ll diff = base2 - base1;
        if (z1 == 0)
            return -1;
        return base2;
    }

    return base1;
    }
};
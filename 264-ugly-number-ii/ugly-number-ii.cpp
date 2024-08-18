class Solution {
public:
    bool u(int x) {
    if (x <= 0) return false;
    while (x % 2 == 0) x /= 2;
    while (x % 3 == 0) x /= 3;
    while (x % 5 == 0) x /= 5;
    return x == 1;
    }

int nthUglyNumber(int n) {
    if (n <= 0) return 0;

    vector<int> uNums(n);
    uNums[0] = 1;

    int i2 = 0, i3 = 0, i5 = 0;
    int m2 = 2, m3 = 3, m5 = 5;

    for (int i = 1; i < n; i++) {
        int next = min(m2, min(m3, m5));
        uNums[i] = next;

        if (next == m2) {
            i2++;
            m2 = uNums[i2] * 2;
        }
        if (next == m3) {
            i3++;
            m3 = uNums[i3] * 3;
        }
        if (next == m5) {
            i5++;
            m5 = uNums[i5] * 5;
        }
    }

    return uNums[n - 1];
    }
};
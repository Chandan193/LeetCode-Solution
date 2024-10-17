class Solution {
public:
    int maximumSwap(int num) {
        int mi = -1, s1 = -1, s2 = -1;
        string ns = to_string(num);
        int n = ns.size();

        for (int i = n - 1; i >= 0; i--) {
            if (mi == -1 || ns[i] > ns[mi]) {
                mi = i;
            } else if (ns[i] < ns[mi]) {
                s1 = i;
                s2 = mi;
            }
        }

        if (s1 != -1 && s2 != -1) {
            swap(ns[s1], ns[s2]);
        }

        return stoi(ns);
    }
};
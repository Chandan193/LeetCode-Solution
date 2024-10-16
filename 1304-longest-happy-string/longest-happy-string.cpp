class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
    string res = "";
    vector<pair<int, char>> v = {{a, 'a'}, {b, 'b'}, {c, 'c'}};
    while (true) {
        sort(v.rbegin(), v.rend());
        bool added = false;
        for (auto &[cnt, ch] : v) {
            if (cnt == 0) continue;
            int len = res.size();
            if (len >= 2 && res[len - 1] == ch && res[len - 2] == ch) continue;
            res += ch;
            cnt--;
            added = true;
            break;
        }
        if (!added) break;
    }
    return res;  
    }
};
class Solution {
public:
    string generate(string &cur, char prev, int size, int n, int &k) {
        if(size == n) {
            k--;
            if(k == 0) return cur;
            return "";
        }
        for(char c = 'a'; c <= 'c'; c++) {
            if(c != prev) {
                cur += c;
                auto result = generate(cur, c, size + 1, n, k);
                cur.pop_back();
                if(result != "") return result;
            }
        }
        return "";
    }

    string getHappyString(int n, int k) {
       string cur = "";
    return generate(cur, 'z', 0, n, k);
    }
};
class Solution {
public:
string largestNumber(vector<int>& n) {
    vector<string> v;
    for (int i : n) v.push_back(to_string(i));
    sort(v.begin(), v.end(), [](string &a, string &b) {
        return a + b > b + a;
    });
    string r;
    for (string &s : v) r += s;
    return r[0] == '0' ? "0" : r;
}

};
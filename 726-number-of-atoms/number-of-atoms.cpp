class Solution {
public:
    string countOfAtoms(string formula) {
        stack<unordered_map<string, int>> stk;
        stk.push({});
        int i = 0, n = formula.size();

        while (i < n) {
            if (formula[i] == '(') {
                stk.push({});
                i++;
            } else if (formula[i] == ')') {
                auto top = stk.top();
                stk.pop();
                i++;
                int start = i;
                while (i < n && isdigit(formula[i])) i++;
                int ml = start < i ? stoi(formula.substr(start, i - start)) : 1;
                for (auto &p : top) {
                    stk.top()[p.first] += p.second * ml;
                }
            } else {
                int start = i;
                i++;
                while (i < n && islower(formula[i])) i++;
                string atom = formula.substr(start, i - start);
                start = i;
                while (i < n && isdigit(formula[i])) i++;
                int count = start < i ? stoi(formula.substr(start, i - start)) : 1;
                stk.top()[atom] += count;
            }
        }

        auto &fc = stk.top();
        vector<pair<string, int>> ele(fc.begin(), fc.end());
        sort(ele.begin(), ele.end());

        string ans;
        for (const auto &e : ele) {
            ans += e.first;
            if (e.second > 1) {
                ans += to_string(e.second);
            }
        }

        return ans;
    }
};
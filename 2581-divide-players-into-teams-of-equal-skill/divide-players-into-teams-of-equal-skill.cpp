class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
    sort(skill.begin(), skill.end());
    int n = skill.size(), sum = skill[0] + skill[n-1];
    long long res = 0;
    for (int i = 0; i < n / 2; ++i) {
        if (skill[i] + skill[n-i-1] != sum) return -1;
        res += 1LL * skill[i] * skill[n-i-1];
    }
    return res;
    }
};
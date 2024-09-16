class Solution {
public:
    int findMinDifference(vector<string>& t) {
       vector<int> arr(t.size());
        
        for (int i = 0; i < t.size(); i++) {
            int h = stoi(t[i].substr(0, 2));
            int m = stoi(t[i].substr(3));
            arr[i] = h * 60 + m;
        }

        sort(arr.begin(), arr.end());

        int minDiff = INT_MAX;
        for (int i = 0; i < arr.size() - 1; i++) {
            minDiff = min(minDiff, arr[i + 1] - arr[i]);
        }

        minDiff = min(minDiff, 24 * 60 - arr.back() + arr.front());

        return minDiff;
    }
};
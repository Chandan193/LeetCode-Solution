class Solution {
public:
    int findTheWinner(int n, int k) {
        vector<int> temp;
        for(int i=1; i<=n; i++){
            temp.push_back(i);
        }
        int i = 0;
        while(temp.size()>1){
            i = (i + k - 1) % temp.size();
            temp.erase(temp.begin() + i);
        }
    return temp[0];
    }
};
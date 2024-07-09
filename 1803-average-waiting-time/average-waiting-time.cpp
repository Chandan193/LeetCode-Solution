class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
    double n = customers.size();
    double time = customers[0][0] + customers[0][1];
    double wait = customers[0][0];
    double total = (time - wait);
    for(double i=1; i<n; i++){
        wait = customers[i][0];
        time = (time + customers[i][1]) > (customers[i][0] + customers[i][1]) ? time + 
        customers[i][1] : customers[i][0] + customers[i][1];
        total += (time - wait);
        }
        return (total/n);
    }
};
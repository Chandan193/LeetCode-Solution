class Solution {
public:
    string h(int n, vector<string>& l20, vector<string>& tn) {
        if (n == 0) return "";
        else if (n < 20) return l20[n] + " ";
        else if (n < 100) return tn[n / 10] + " " + h(n % 10, l20, tn);
        else return l20[n / 100] + " Hundred " + h(n % 100, l20, tn);
    }

    string numberToWords(int n) {
        if (n == 0) return "Zero";
 
        vector<string> t = {"", "Thousand", "Million", "Billion"};
        vector<string> l20 = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine" ,
        "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", 
        "Nineteen"};
        vector<string> tn = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", 
        "Ninety"};
        
        string res;
        int i = 0;
        
        while (n > 0) {
            if (n % 1000 != 0) {
                res = h(n % 1000, l20, tn) + t[i] + " " + res;
            }
            n /= 1000;
            i++;
        }
        while (res.back() == ' ') res.pop_back();
        return res;
    }
};
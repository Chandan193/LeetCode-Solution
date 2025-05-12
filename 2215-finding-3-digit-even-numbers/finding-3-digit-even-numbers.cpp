class Solution {
public:
    void fun(int x, int y, int z, set<int>& st){
        int n1, n2, n3, n4, n5, n6;
        if(x%2==0){
        n1 = x + (y*10) + (z*100);
        if(n1>=100) st.insert(n1);
        n2 = x + (z*10) + (y*100);
        if(n2>=100) st.insert(n2);
        }

        if(y%2==0){
        n3 = y + (x*10) + (z*100);
        if(n3>=100) st.insert(n3);
        n4 = y + (z*10) + (x*100);
        if(n4>=100) st.insert(n4);
        }

        if(z%2==0){
        n5 = z + (x*10) + (y*100);
        if(n5>=100) st.insert(n5);
        n6 = z + (y*10) + (x*100);
        if(n6>=100) st.insert(n6);
        }
    }
    vector<int> findEvenNumbers(vector<int>& digits) {
        set<int> st;
        int n = digits.size();
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                for(int k=j+1; k<n; k++){
                    if(digits[i]%2==0 || digits[j]%2==0 || digits[k]%2==0) 
                        fun(digits[i], digits[j], digits[k], st);
                }
            }
        }

        vector<int> ans;

        for(auto i : st) ans.push_back(i);

        return ans;
    }
};
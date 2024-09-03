class Solution {
public:
    int digSum(int num){
        int ans = 0;
        while(num>0){
            int ld = num%10;
            ans += ld;
            num /= 10;
        }
        return ans;
    }
    int getLucky(string s, int k) {
        unordered_map<char, string> mp = {
        {'a',"1"}, {'b',"2"}, {'c',"3"}, {'d',"4"}, {'e',"5"}, {'f',"6"}, {'g',"7"}, {'h',"8"}, 
        {'i',"9"}, {'j',"10"}, {'k',"11"}, {'l',"12"}, {'m',"13"}, {'n',"14"}, {'o',"15"}, 
        {'p',"16"}, {'q',"17"}, {'r',"18"}, {'s',"19"}, {'t',"20"}, {'u',"21"}, {'v',"22"}, 
        {'w',"23"}, {'x',"24"}, {'y',"25"}, {'z',"26"}
        };
        int num=0;
        for(char c : s){
            num += digSum(stoi(mp[c]));
        }

        if(k==1) return num;

        int tn = k-1;

        int ans = num;
        
        while(tn>0){
        ans = digSum(ans);
        if(ans<10) return ans;
        tn--;
        }

        return ans;
    }
};
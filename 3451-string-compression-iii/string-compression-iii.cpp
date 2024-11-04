class Solution {
public:
    string compressedString(string word) {
        string comp = "";
        int i = 0;
        int n = word.size();
        
        while (i < n) {
            char c = word[i];
            int count = 1;
            while (count < 9 && i + count < n && word[i + count] == c) {
                count++;
            }
            comp += to_string(count) + c;
            i += count;
        }
        
        return comp;
    }
};
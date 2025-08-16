class Solution {
public:
    int maximum69Number (int num) {
        string s = to_string(num);
        
        // Find the first '6' and change it to '9' but not vice-versa as it'll decrease the number
        for (char &c : s) {
            if (c == '6') {
                c = '9';
                break; // Only one change allowed
            }
        }
        
        return stoi(s);
    }
};

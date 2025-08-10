class Solution {
public:
    bool reorderedPowerOf2(int n) {
        std::string s = std::to_string(n);
        std::sort(s.begin(), s.end());
        do {
            if (s[0] == '0') continue;
            try {
                int num = stoi(s);
                if (num > 0 && (num & (num - 1)) == 0) {
                    return true;
                }
            } catch (const out_of_range& oor) {
                continue; 
            }
        } while (next_permutation(s.begin(), s.end()));
        return false;
    }
};

class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string s=tostring(n);
        for(int i=0;i<31;i++){
            int m=1<<i;
            if(s==tostring(m))
            return true;
        }
        return false;

        
    }
    string tostring(int n){
        string s=to_string(n);
        sort(s.begin(),s.end());
        return s;
    }
};

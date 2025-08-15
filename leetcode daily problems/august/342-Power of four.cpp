class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n<0)return false;
        
        return n>0 && !(n &(n-1)) && ((n-1)%3==0);
        
    }
};

class Solution {
    public:
    int popcount(long long x){
        int count=0;
        while(x>0){
            x&=(x-1);
            count++;
        }
        return count;
    }
    int makeTheIntegerZero(int num1, int num2) {
        for(int k=1;k<=60;k++){
            long long target=num1-(long long)num2*k;
            if(target>=k && popcount(target)<=k)
            return k;
        }
        return -1;
    }
};
//TC=O(60∗Log(Num1))
//SC=O(1)

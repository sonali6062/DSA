class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long int n=nums.size();
        long long int count=0;
        long long int streak=0;
        for(int num:nums){
            if(num==0){
                streak++;
                count+=streak;
            }
            else
            streak=0;
        }
        return count;
        
    }
};

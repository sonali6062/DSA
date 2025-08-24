class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n=nums.size();
        int left=0,zeroCount=0,maxlen=0;
        int right=0;
        for(right=0;right<n;right++){
            if(nums[right]==0)
            zeroCount++;
            while(zeroCount>1){
                if(nums[left]==0)
                zeroCount--;
                left++;
            }
            maxlen=max(maxlen,right-left);
        }
        return maxlen;
    }
};
TC=O(N)
//internal while loop has constant iterations so we consider it as constant
SC=O(!)

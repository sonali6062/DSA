class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        int n=nums.size();
        vector<int>res;
        for(int num:nums){
            res.push_back(num);
            while(res.size()>1){
                int a=res.back();
                int b=res[res.size()-2];
                int g=gcd(a,b);
                if(g>1){
                    res.pop_back();
                    res.pop_back();
                    long long lcm=a/ g*b;
                    res.push_back(lcm);
                }
                else
                break;
            }

        }
        return vector<int>(res.begin(),res.end());
        
    }
};

//TC=O(N)
//SC=O(N)

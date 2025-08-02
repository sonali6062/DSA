class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        int n1=basket1.size();
        int n2=basket2.size();
        
        unordered_map<int,int>mpp;
        for(int i:basket1){
            mpp[i]++;
        }
        for(int i:basket2){
            mpp[i]--;
        }
        int minEle=INT_MAX;
        vector<int>temp;
        for(auto& [u,v]:mpp){
            if(v%2==1)return -1;
            for(int i=0;i<abs(v)/2;i++){
                temp.push_back(u);
            }
            minEle=min(minEle,u);
        }
        sort(temp.begin(),temp.end());
        long long ans=0;
        for(int i=0;i<temp.size()/2;i++){
            ans+=min(temp[i],2*minEle);
        }
        return ans;


        
    }
};
//TC=O(N)
//SC=O(N)

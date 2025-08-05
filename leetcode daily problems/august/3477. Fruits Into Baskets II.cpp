class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int ans=fruits.size();
        for(int x:fruits){
            for(int &B:baskets){
                if(x<=B){
                    ans--;
                    B=0;
                    break;
                }
            }
        }
        return ans;
        
    }
};
//tc=O(N*M)
//SC=O(1)
METHOD 2:
class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=fruits.size();
        vector<bool>used(n,false);
        int count=0;
        for(int i=0;i<n;i++){
            bool placed=false;
            for(int j=0;j<n;j++){
                if(!used[j] && baskets[j]>=fruits[i] ){
                    used[j]=true;
                    placed=true;
                    break;
                }
            }
            if(!placed) count++;
        }
        return count;
        
    }
};

class Solution {
public:
# define ll long long 
    long long flowerGame(int n, int m) {
        ll count=0;
        int odd_lane=(n+1)/2;
        int even_lane= m/2;
        count+=(1ll * odd_lane* even_lane);

        int even_lane1=n/2;
        int odd_lane2=(m+1)/2;
        count+=(1ll *even_lane1* odd_lane2);
        return count;
        
    }
};
//TC=O(1)
//SC=O(1)


//TABULISATION
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp = triangle[n-1]; 

        for (int i = n - 2; i >= 0; i--) {
            for (int j = 0; j <= i; j++) {
                dp[j] = triangle[i][j] + min(dp[j], dp[j+1]);
            }
        }

        return dp[0];
    }
};

//MEMOIZATION
class Solution {
public:
int f(long long int n,long long int totalsum,vector<vector<int>>&triangle,vector<vector<long long int>>&dp){
   if (n == triangle.size() - 1) return triangle[n][totalsum];

    if(dp[n][totalsum]!=-1)return dp[n][totalsum];
    long long int down=f(n+1,totalsum,triangle,dp);
    long long int up=f(n+1,totalsum+1,triangle,dp);
    return triangle[n][totalsum]+min(up,down);

}
    int minimumTotal(vector<vector<int>>& triangle) {
        long long int n=triangle.size();
        long long int pathweight=0;
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<i+1;i++){
        //         pathweight=triangle[i][j];
        //     }
        // }
        vector<vector<long long int>>dp(n+1,vector<long long int>(n+1,-1));
        return f(0,0,triangle,dp);
        
    }
};

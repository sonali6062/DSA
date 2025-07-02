class Solution {
public:
    static constexpr int mod=1e9+7;
    int possibleStringCount(string& word, int k) {
        const int n=word.size();
        if (n<k) return 0;// edge case
        if (n==k) return 1;

        // Deal with segments of consecutive same letters
        vector<int> seg={1};
        for (int i=1; i<n; i++)
            if (word[i]==word[i-1]) seg.back()++;
            else seg.push_back(1);
        const int m=seg.size();

        // number of all total typed string, each seg has at least 1
        long long total=1;
        bool takeMod=0;
        for(int x: seg){
            total*=x;
            if (total>=mod) {
                total%=mod;
                takeMod=1;
            }
        }
        if (total==1 && !takeMod) return 1; // special case

        if (k<=m) return total;

        // invalid strings where original len < k
        // Use Prefix sum & DP to count based on the following inequalities
        // z0+z1+....+z[m-1]<=k-m-1
        // 0<=zi<=si-1=seg[i]-1
        int maxT=k-m-1;
        long long dp[2][2000]={0}, prefix[2001]={0};
        dp[0][0]=1;

        for (int j=0; j<m; j++) {
            const int s=seg[j];
            for (int i=0; i<=maxT; i++){
                prefix[i+1]=(prefix[i]+dp[j&1][i])%mod;// 1-indexed prefix sum
                int L=max(0, i-(s-1)), R=i;
                dp[(j+1)&1][i]=(prefix[R+1]-prefix[L]+mod)%mod;
            }
        }

        long long lessK=0;
        for (long long x : dp[m&1])
            lessK=(lessK+x)%mod;

        return (total-lessK+mod) % mod;
    }
};
auto init = []()
{ 
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    return 'c';
}();
/*
class Solution {
public:
    const int MOD = 1e9 + 7;

    int possibleStringCount(string word, int k) {
        int n = word.size();
        if (n < k) return 0;

        // Step 1: Group consecutive characters
        vector<int> groups;
        int count = 1;
        for (int i = 1; i < n; ++i) {
            if (word[i] == word[i - 1]) {
                count++;
            } else {
                groups.push_back(count);
                count = 1;
            }
        }
        groups.push_back(count);  // last group

        // dp[i] = number of ways to build string of length i
        vector<int> dp(n + 1, 0);
        dp[0] = 1;

        for (int g : groups) {
            // Compute prefix sum of dp
            vector<int> prefix(n + 2, 0);
            for (int i = 0; i <= n; ++i) {
                prefix[i + 1] = (prefix[i] + dp[i]) % MOD;
            }

            vector<int> new_dp(n + 1, 0);
            for (int len = 1; len <= n; ++len) {
                if (len - 1 - g >= 0) {
                    new_dp[len] = (prefix[len] - prefix[len - g] + MOD) % MOD;
                } else {
                    new_dp[len] = prefix[len];
                }
            }
            dp = new_dp;
        }

        // Final result: sum of dp[i] for i >= k
        int result = 0;
        for (int i = k; i <= n; ++i) {
            result = (result + dp[i]) % MOD;
        }
        return result;
    }
};*/

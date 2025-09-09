class Solution {
public:
    int peopleAwareOfSecret(int n, int delay, int forget) {
        const int MOD = 1e9 + 7;
        vector<long long> dp(n + 1, 0); // dp[i]: number of people learning the secret on day i
        dp[1] = 1; // On day 1, one person knows the secret
        long long active = 0; // Number of people who can share the secret today

        for (int day = 2; day <= n; ++day) {
            // People who start sharing today
            long long start_sharing = (day - delay >= 1) ? dp[day - delay] : 0;
            // People who forget the secret today
            long long forget_today = (day - forget >= 1) ? dp[day - forget] : 0;

            active = (active + start_sharing - forget_today + MOD) % MOD;
            dp[day] = active;
        }

        // Count the total number of people who still know the secret at the end of day n
        long long result = 0;
        for (int day = n - forget + 1; day <= n; ++day) {
            if (day >= 1)
                result = (result + dp[day]) % MOD;
        }

        return result;
    }
};
//tc=sc=O(n)

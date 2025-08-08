class Solution {
public:
    // Max scaled n is 192 (4800 / 25)
    double memoisation[193][193];

    // DFS with memoization
    double dfs(int a, int b) {
        // Base cases
        if (a <= 0 && b <= 0) return 0.5; // Both empty at same time
        if (a <= 0) return 1.0;           // A finishes first
        if (b <= 0) return 0.0;           // B finishes first

        // Memoized result
        if (memoisation[a][b] != -1.0) return memoisation[a][b];

        // Recursively compute probability
        double prob = 0.25 * (
            dfs(a - 4, b) +
            dfs(a - 3, b - 1) +
            dfs(a - 2, b - 2) +
            dfs(a - 1, b - 3)
        );

        return memoisation[a][b] = prob;
    }

    double soupServings(int n) {
        // Optimization: for large n, result approaches 1
        if (n >= 4800) return 1.0;

        // Initialize memoization array with -1
        for (int i = 0; i < 193; ++i)
            for (int j = 0; j < 193; ++j)
                memoisation[i][j] = -1.0;

        // Scale down: each unit = 25 ml
        int m = ceil(n / 25.0);

        return dfs(m, m);
    }
};
TC=O(m^2)
SC=O(m^2)

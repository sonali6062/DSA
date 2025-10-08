class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
    int m = potions.size();
    vector<int> result;

    for (int spell : spells) {
        // Minimum required potion strength for this spell
        long long required = (success + spell - 1) / spell;  // ceil(success / spell)

        // Find the first potion >= required using binary search
        int idx = lower_bound(potions.begin(), potions.end(), required) - potions.begin();

        // Count of successful pairs for this spell
        int count = m - idx;
        result.push_back(count);
    }

    return result;
    }
};

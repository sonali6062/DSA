
class Solution {
public:
    int minimumDeletions(string word, int k) {
        unordered_map<char, int> freq_mpp;
        for (char ch : word) {
            freq_mpp[ch]++;
        }
        
        int res = word.size(); // Initialize with the maximum possible deletions 
        
        for (auto& entry1 : freq_mpp) {
            int f = entry1.second;
            int deleted = 0;
            for (auto& entry2 : freq_mpp) {
                int current_freq = entry2.second;
                if (current_freq < f) {
                    deleted += current_freq;
                } else if (current_freq > f + k) {
                    deleted += current_freq - (f + k);
                }
            }
            res = min(res, deleted);
        }
        
        return res;
    }
};

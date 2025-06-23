class Solution {
private:
    // Check if a string is palindrome
    bool isPalindrome(const string &s) {
        return s == string(s.rbegin(), s.rend());
    }

    // Convert number to base-k
    string toBaseK(long long num, int k) {
        string res;
        while (num > 0) {
            res += char('0' + num % k);
            num /= k;
        }
        reverse(res.begin(), res.end());
        return res;
    }

    // Generate palindromes and check base-k palindromes
    void generatePalindromes(vector<long long> &result, int k, int n) {
        int length = 1;
        while (result.size() < n) {
            // Generate odd-length palindromes
            for (int half = pow(10, (length - 1) / 2); result.size() < n && half < pow(10, (length + 1) / 2); ++half) {
                string s = to_string(half);
                string rev = s;
                reverse(rev.begin(), rev.end());
                // remove last digit for odd-length palindromes
                if (length % 2) rev = rev.substr(1);
                string full = s + rev;
                long long num = stoll(full);
                if (isPalindrome(toBaseK(num, k))) {
                    result.push_back(num);
                }
            }
            length++;
        }
    }

public:
    long long kMirror(int k, int n) {
        vector<long long> palindromes;
        generatePalindromes(palindromes, k, n);
        long long sum = 0;
        for (int i = 0; i < n; ++i)
            sum += palindromes[i];
        return sum;
    }
};

class Solution {
public:
    // Convert a string to lowercase
    string toLower(const string &word) {
        string result = word;
        for (char &c : result)
            c = tolower(c);
        return result;
    }
    
    // Replace vowels with '*'
    string devowel(const string &word) {
        string result = word;
        for (char &c : result) {
            if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
                c = '*';
        }
        return result;
    }
    
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_set<string> exactMatch(wordlist.begin(), wordlist.end());
        unordered_map<string, string> caseMap;
        unordered_map<string, string> vowelMap;
        
        // Preprocess the wordlist
        for (const string &word : wordlist) {
            string lowerWord = toLower(word);
            string devowelWord = devowel(lowerWord);
            
            if (caseMap.find(lowerWord) == caseMap.end())
                caseMap[lowerWord] = word;
            
            if (vowelMap.find(devowelWord) == vowelMap.end())
                vowelMap[devowelWord] = word;
        }
        
        vector<string> result;
        
        // Process each query
        for (const string &query : queries) {
            // 1. Exact match
            if (exactMatch.find(query) != exactMatch.end()) {
                result.push_back(query);
                continue;
            }
            
            // 2. Case-insensitive match
            string lowerQuery = toLower(query);
            if (caseMap.find(lowerQuery) != caseMap.end()) {
                result.push_back(caseMap[lowerQuery]);
                continue;
            }
            
            // 3. Vowel-error match
            string devowelQuery = devowel(lowerQuery);
            if (vowelMap.find(devowelQuery) != vowelMap.end()) {
                result.push_back(vowelMap[devowelQuery]);
                continue;
            }
            
            // 4. No match
            result.push_back("");
        }
        
        return result;
    }
};

class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n=s.size();
        vector<string>result;
        for(int i=0;i<n;i+=k){
            string group=s.substr(i,k);
            if(group.size()<k)
            group.append(k-group.size(),fill);
            result.push_back(group);

        }
        return result;
    }
};

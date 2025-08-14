class Solution {
public:
    string largestGoodInteger(string num) {
        int n=num.size();
        string ans="";
        string candidate="";
        for(int i=2;i<n;i++){
            if(num[i]==num[i-1] && num[i]==num[i-2])
            candidate=num.substr(i-2,3);
             if (candidate > ans) { 
                    ans = candidate;
                }
        }
        return ans;
    }
};

class Solution {
public:
    string sortVowels(string s) {
        int n=s.size();
        vector<char>ch;
        for(char c:s){
            if(isVowel(c)){
                ch.push_back(c);

            }
        }
        sort(ch.begin(),ch.end());
        int v_index=0;
        for(char &c:s){
            if(isVowel(c)){
                c=ch[v_index++];
            }
        }

        return s;
    }
    bool isVowel(char c){
        switch(c){
            case 'A':case 'E':case 'I':case 'O':case 'U':
            case 'a':case 'e':case 'i':case 'o':case 'u':
            return true;
            default:
            return false;

        }
    }
};
//TC=O(Nlogn)
//SC=O(N)

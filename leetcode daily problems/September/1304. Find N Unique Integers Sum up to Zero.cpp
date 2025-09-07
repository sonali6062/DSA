class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int>res(n);
        int temp=n/2;
        int start=0,end=n-1;
        while(start<end){
            res[start]=-temp;
            res[end]=temp;
            temp--;
            start++;
            end--;
        }
        return res;
    }
};
//TC=O(N)
//SC=O(N)

class Solution {
public:
    vector<int> mergeSort(vector<int>& nums) {
        if(nums.size()<=1)
        return nums;
        int mid=nums.size()/2;
        vector<int>left(nums.begin(),nums.begin()+mid);
        vector<int>right(nums.begin()+mid,nums.end());
        left=mergeSort(left);
        right=mergeSort(right);
        return merge(left,right);

    }
    private:
    vector<int>merge(vector<int>&left,vector<int>&right){
       vector<int>sorted;
       int i=0,j=0;
       while(i<left.size() && j<right.size()){
        if(left[i]<=right[j]){
            sorted.push_back(left[i]);
            i++;
        }else{
            sorted.push_back(right[j]);
            j++;
        }
       
       }
        while(i<left.size()){
            sorted.push_back(left[i]);
            i++;
        }
        while(j<right.size()){
            sorted.push_back(right[j]);
            j++;
        }
        return sorted;
    }
};

class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n=nums.size();
        vector<int>res;
        for(int i=0;i<n;i++){
            if(nums[i]==key)
            res.push_back(i);
        }
         set<int> resultSet; // To avoid duplicates
        for (int j : res) {
            int start = max(0, j - k);
            int end = min(n - 1, j + k);
            for (int i = start; i <= end; ++i) {
                resultSet.insert(i);
            }
        }

        // Step 3: Copy to result vector in sorted order
        vector<int> result(resultSet.begin(), resultSet.end());
        return result;
    }
};

class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int n=dimensions.size();
        int m=dimensions[0].size();
        int area=0,maxdiag=0;
        for(int i=0;i<n;i++){
            int length=dimensions[i][0];
            int width=dimensions[i][1];
            int diagonal=length*length+ width* width;
            int currArea=length*width;
            if(maxdiag<diagonal){
                maxdiag=diagonal;
                area=currArea;
            }
            else if(maxdiag==diagonal){
                area=max(area,currArea);
            }

        }
        return area;

        
    }
};
//TC=O(N)
//SC=O(1)

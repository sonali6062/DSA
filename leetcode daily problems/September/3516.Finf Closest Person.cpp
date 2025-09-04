class Solution {
public:
    int findClosest(int x, int y, int z) {
        
        //both are approaching with same velocity
        int d1=abs(z-x);
        int d2=abs(z-y);
        if (d1 < d2) return 1;   // Person 1 is closer
        else if (d2 < d1) return 2; // Person 2 is closer
        else return 0;   
        
    }
};
//TC=O(1)
//SC=O(1)

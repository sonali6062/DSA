class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int count = numBottles;   
        int empty = numBottles;   
        while (empty >= numExchange) {
            int newBottles = empty / numExchange; // how many new full bottles we can get
            count += newBottles;                  // drink them
            empty = empty % numExchange + newBottles; // leftover empties + newly drunk ones
        }

        return count;
    }
};

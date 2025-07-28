Imagine you have a special keyboard with the following keys:
A: Print one 'A' on the screen.
Ctrl-A: Select the whole screen.
Ctrl-C: Copy selection to buffer.
Ctrl-V: Print buffer on screen appending it after what has already been printed.
Given an integer n, return the maximum number of 'A' you can print on the screen with at most n presses on the keys.

Examples:
Input: n = 3
Output: 3
Explanation: We can at most get 3 A's on screen by pressing the following key sequence:
A, A, A

Input: n = 7
Output: 9
Explanation: We can at most get 9 A's on screen by pressing following key sequence:
A, A, A, Ctrl A, Ctrl C, Ctrl V, Ctrl V

class Solution {
public:
    int maxA(int n) {
        // Your code goes here
        return helper(n,0,0);

    }
    private:
    int helper(int n,int screen,int buffer){
        if(n<=0)
        return screen;
        int pressA=helper(n-1,screen+1,buffer);
        int pressCtrlV=helper(n-1,screen+buffer,buffer);
        int pressCtrlACtrlC=0;
        if(n>=2){
            pressCtrlACtrlC=helper(n-2,screen,screen);

        }
        return max({pressA,pressCtrlV,pressCtrlACtrlC});
    }
};
TC=O(3^n)
SC=O(n)(due to recursion stack)

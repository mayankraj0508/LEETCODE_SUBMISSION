class Solution {
public:
    bool checkGoodInteger(int n) {
        int square = 0;
        int sum  = 0;
        while(n>0){
            int rem = n%10;
            sum  = sum + rem;
            square = square + rem*rem;
            n = n/10;
        }
        return square-sum>=50;
        
    }
};
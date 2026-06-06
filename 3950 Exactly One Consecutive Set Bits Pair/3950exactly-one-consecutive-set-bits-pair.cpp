class Solution {
public:
    bool consecutiveSetBits(int n) {
          int x = n & (n >> 1);
          return x && ((x & (x - 1)) == 0);
        
        
    }
};
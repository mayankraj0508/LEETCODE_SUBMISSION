class Solution {
public:
    bool check(int x){
        bool changed = false;

        while(x > 0){
            int rem = x % 10;

            if(rem == 3 || rem == 4 || rem == 7){
                return false;
            }

            if(rem == 2 || rem == 5 || rem == 6 || rem == 9){
                changed = true;
            }

            x /= 10;
        }

        return changed;
    }

    int rotatedDigits(int n) {
        int count = 0;
        for(int i = 1; i <= n; i++){
            if(check(i)){
                count++;
            }
        }
        return count;
    }
};
class Solution {
public:
    int reverse(int n) {
        int x = 0;
        while(n > 0) {
            x= x * 10 + (n % 10);
            n /= 10;
        }
        return x;
    }

    bool check(int x) {
        if(x < 2) return false;
        for(int i = 2; i * i <= x; i++) {
            if(x % i == 0) return false;
        }
        return true;
    }

    int sumOfPrimesInRange(int n) {
        int r = reverse(n);
        int L = min(n, r);
        int R = max(n, r);
        int sum = 0;
        for(int i = L; i <= R; i++) {
            if(check(i)) {
                sum += i;
            }
        }

        return sum;
    }
};
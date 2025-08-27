class Solution {
public:
    int f(int n){
        return 1 << n;
    }

    int divide(int dividend, int divisor) {
        long long a = llabs((int)dividend);
        long long b = llabs((int)divisor);
        int pivot;
        if(dividend == INT_MIN && divisor == -1){
            return INT_MAX;
        }
        if(dividend==INT_MIN&&divisor==1){
            return INT_MIN;
        }
        for(int i = 0; i < 500; i++){
            if((b << i) > a){
                pivot = i - 1;
                break;
            }
        }
        vector<int> quo;
        while (pivot >= 0) {
            if((b << pivot) == a){
                quo.push_back(pivot);
                break;
            }
            if ((b << pivot) < a) {
                a -= (b << pivot);
                quo.push_back(pivot);
            }
            pivot--;
        }
        int ans = 0;
        for(int i = 0; i < quo.size(); i++){
            ans = ans + f(quo[i]);
        }
        if((dividend < 0) ^ (divisor < 0)){
            return -ans;
        }
        return ans;
    }
};

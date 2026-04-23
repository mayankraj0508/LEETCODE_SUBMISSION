class Solution {
public:
    long long removeZeros(long long n) {
        long long final_ans = 0;
        long long place  = 1;
        while(n>=1){
            int rem = n%10;
            n=  n/10;
            if(rem==0){
                continue;
            }
            else{
                final_ans = final_ans+rem*place;
                place  = place*10;
            }
            
        }
        return final_ans;
        
    }
};
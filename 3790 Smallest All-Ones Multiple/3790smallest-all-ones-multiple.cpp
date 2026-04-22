class Solution {
public:
    int minAllOneMultiple(int k) {
        long long  num = 0;
        int p =0;
        while(p<k){
            num = (num*10+1)%k;
            p++;
            if(num%k==0){
                return p;
            }
            
        }
        return -1;
        
    }
};
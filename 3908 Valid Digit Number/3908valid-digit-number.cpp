class Solution {
public:
    bool validDigit(int n, int x) {
        bool flag = false ;
        while(n>0){
            int rem = n%10;
            n = n/10;
            if(n==0 && rem==x){
                return false;
            }
            if(rem==x){
                flag = true;
            }
            
            
            
        }
        return flag;
        
    }
};
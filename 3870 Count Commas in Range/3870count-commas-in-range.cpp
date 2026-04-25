class Solution {
public:
    int f(int n){
        if(n>=1000 && n<100000){
            return 1;
        }
        else{
            return 2;
        }
    }
    int countCommas(int n) {
        if(n<1000){
            return 0;
        }
        if(n<100000){
            int offset = (n-1000)+1;
            return offset;
        }
        else{
            if(n>=100000){
                int offset = ((n-100000)+1)*2+99000-1;
                return offset;
            }
        }
        return 0;
        
        
    }
};
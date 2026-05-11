class Solution {
public:
    int reverse(long long x) {
     /*   if(x<0){
            if(-x/10>INT_MAX/10||-x/10<INT_MIN/10){
                return 0;
            }
        }*/
        int revnum = 0;
        long long l;
        if(x<0){
            l = -x; 

        }
        else{
            l =x;
        }
        int k;
        
        int p = l/10;
        int f = INT_MAX/10;
        int h = INT_MIN/10;
        
        
        while(l>0){
            k = l%10;
            l = l/10;
            if(revnum>INT_MAX/10||revnum<INT_MIN/10){
                return 0;
            }

            revnum = revnum*10+k;

            
        }
        
        if(x<0){
            return -revnum;
        }
        else{
        return revnum;
        }

        
    }
};
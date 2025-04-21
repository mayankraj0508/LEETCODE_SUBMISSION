class Solution {
public:
    int mySqrt(int x) {
        int lo = 1;
        int hi = x;
        long long mid = lo + (hi-lo)/2;
        if(x==0){
            return 0;
        }
        while(lo<=hi){
             mid = lo + (hi-lo)/2;
            if(mid*mid==x){
                return mid;
            }
            else if(mid*mid<x){
               /* if((mid+1)*(mid+1)==x){
                    return mid+1;
                }*/
                if((mid+1)*(mid+1)>x){
                    return mid;
                }
                lo =mid + 1;
            }
            else{
              /*  if((mid-1)*(mid-1)==x){
                    return mid-1;
                }
                if((mid-1)*(mid-1)>x){
                    return mid-1;
                }*/
                hi = mid-1;
            }
        }
      /*  if(lo==hi){
            return lo;
        }*/
   
       return mid;
    }
};
class Solution {
public:
    bool isPalindrome(int x) {
        int u = x;
        if(x==0){
            return true;
        }
        if(x<0||x%10==0){
            return false;
        }
        

        long long   revnum  = 0;
        int k;
       int y = INT_MAX;
      int z = INT_MIN;
      int p = x/10;
        if(p>y/10 || p<z/10){
                return false;
            }
        
        while(x>0){
            k = x%10;            
            x = x/10;
          
            
            revnum = revnum*10+k;
            

           
        }
                    
        
        if(revnum==u){
            return true;
        }
        return false;
        
    }
};
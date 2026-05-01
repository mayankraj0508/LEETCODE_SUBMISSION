class Solution {
public:
    bool canAliceWin(int n) {
        if(n<10){
            
            return false;
        }
        n = n-10;
        int   turn   = 0;
        int val = 9;
        if(n<9){
            return true;
        }
         while(n>=val){
             n = n-val;
             turn  = !turn;
             val--;
         }
        if(turn==1){
            return false;
        }
        return true;

        
    }
};
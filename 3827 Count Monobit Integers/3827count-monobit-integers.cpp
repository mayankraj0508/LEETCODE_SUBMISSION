class Solution {
public:
    bool check(int x){
        string final = "";
        while(x>0){
            int rem = x%2;
            x = x/2;
            if(rem==0){
                final = '0'+final;
            }
            else{
                final = '1'+final;
            }
            
        }
        char a = final[0];
        for(int i=0; i<final.size(); i++){
            if(final[i]!=a){
                return false;
            }
        }
        return true;
    }
    int countMonobit(int n) {
        int count = 0;
        for(int i =0; i<=n; i++){
            if(check(i)){
                count++;
            }
        }
        return count;
        
    }
};
class Solution {
public:
       bool checkprime(int n){
            if(n==1){
                return false;

            }
            for(int i =2; i<=sqrt(n);i++){
                if(n%i==0){
                    return false;
                }
            }
            return true;
        }
    int diagonalPrime(vector<vector<int>>& nums) {
        int l  = 0;
        int k = nums.size();
        int p = nums[0].size();
    
        for(int i =0; i<k;i++){
            
                
                    if(checkprime(nums[i][i])==true){
                        l = max(nums[i][i],l);
                    
                }
        }
        for(int i =0;i<k;i++ ){
                
                
                    if(checkprime(nums[i][k-i-1])){
                    
                        l =max(nums[i][k-i-1],l);
                        
                    }
        }
                
            
        
       
        return l;



       

        

    }
};
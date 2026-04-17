class Solution {
public:
    bool check(int num){
        if(num==1){
            return false;
        }
        if(num==2||num==3){
            return true;
        }
        for(int i=2 ; i*i<=num; i++){
            if(num%i==0){
                return false;
            }
        }
        return true;
    }
    int fp(int val){
        int pre = val;
        while(true){
            if(check(val)){
                return val-pre;
            }
            else{
                val++;
            }
            
        }
        
        return val-pre;
    }
        int fnp(int val){
        int pre = val;
        while(true){
            if(!check(val)){
                return val-pre;
            }
            else{
                val++;
            }
            
        }
        return val-pre;
    }
    int minOperations(vector<int>& nums) {
        int x = 0;
        int n = nums.size();
         for(int i =0; i<n; i++){
             if(i%2==0){
                 if(check(nums[i])){
                     continue;
                 }
                 else{
                     x = x+fp(nums[i]);
                 }
             }
             else{
                 if(!check(nums[i])){
                     continue;
                 }
                 else{
                     x = x+fnp(nums[i]);
                 }
             }
         }
        return x;
        
    }
};
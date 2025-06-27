class Solution {
public:
    bool check(int n){
        if(n==1){
            return false;
        }
        if(n==2){
            return true;
        }
        for(int i=2; i<=n/2;i++){
            if(n%i==0){
                return false;
            }
        }
        return true;
    }
    bool checkPrimeFrequency(vector<int>& nums) {
        unordered_map<int,int>m;
        for(int i =0; i<nums.size();i++){
            m[nums[i]]++;
        }
       for(int i=0; i<nums.size();i++){
           if(check(m[nums[i]])==true){
               return true;
           }
       }
        return false;
        
    }
};
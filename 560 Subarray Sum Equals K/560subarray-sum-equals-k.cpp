class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {  
        int n  = nums.size();
        int sum = 0;
          int count = 0;
        unordered_map<int,int>m;
        for(int i =0; i<n; i++){
            sum = sum + nums[i];
                if(i!=0){
         if(m.find(sum-k)!=m.end()){
            count= count + m[sum-k];
         } 
         }
            m[sum]++;
             if(sum==k){
            count++;
         } 
      
        }
      
      

         return count;     
    }
   
};
class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
         int n = nums.size();
       /* vector<int>v(n);
       
        for(int i =0; i<n; i++){
            if(i==0){
                v[i]= nums[i];
            
            }
            else{
                v[i]=nums[i]+v[i-1];
            }
        }
        return v;*/
        //other method
        for(int i =1; i<n; i++){
            nums[i]= nums[i]+ nums[i-1];
        }
        return nums;
        
    }
};
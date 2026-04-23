class Solution {
public:  
    static bool cmp (int a , int b){
        return abs(a)>abs(b);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans(n);
       sort(nums.begin(),nums.end(),cmp);
        int k = 0;
        for(int i =0; i<n; i++){
            if(i%2==0){
               ans[i] = nums[k];
                k++;
            }
        }
        for(int i=0; i<nums.size(); i++){
            if(i%2!=0){
                ans[i] =  nums[k];
                k++;
            }
            
        }
        long long even = 0;
         long long odd = 0;
        for(int i =0; i<ans.size(); i++){
            if(i%2==0){
                even=  even+(long long ) abs(ans[i])*(long long)abs(ans[i]);
            }
            else{
                odd = odd+(long long ) abs(ans[i])*(long long) abs(ans[i]);
            }
        }
        long long result = even-odd;
        return result ;
        
    }
};
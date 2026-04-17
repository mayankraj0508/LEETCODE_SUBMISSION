class Solution {
public:
    int f(int x,int digit){
        int c = 0;
        while(x>0){
         
            int rem = x%10;
            x = x/10;
            if(rem==digit){
                c++;
                
            }
        }
        return c;
    }
    int countDigitOccurrences(vector<int>& nums, int digit) {
        int count = 0;
        int n  = nums.size();
        for(int i=0; i<n; i++){
            count = count+f(nums[i],digit);
        }
        return count;
        
        
    }
};
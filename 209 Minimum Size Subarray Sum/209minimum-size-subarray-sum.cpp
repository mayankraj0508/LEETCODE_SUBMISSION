class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int length =0;
        int sum  =0;
        int minlength = INT_MAX;
        int i =0;
        int j =0;
        while(j<n){
            sum  = sum+ nums[j];

        
        while(sum>=target){
            length = j-i+1;
            minlength = min(minlength,length);
            sum = sum-nums[i];
            i++;
        }
        j++;
        }
        if(minlength==INT_MAX){
            return 0;
        }
        else{
        return minlength;
        }


        
    }
};
class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int flip=0;
        int k = 1;
        int i =0;
        int j =0;
        int length = INT_MIN;
        int maxlength = INT_MIN;
        while(j<n){
            if(nums[j]==1){
                j++;
            }
            else{
                if(flip<k){
                    flip++;
                    j++;

                }
                else{
                    length  = j-i-1;
                    maxlength  = max(length,maxlength);
                    while(nums[i]==1)i++;
                    i++;
                    j++;

                }
                
            }

        }
         length  = j-i-1;
                    maxlength  = max(length,maxlength);
                    return maxlength;
        
    }
};
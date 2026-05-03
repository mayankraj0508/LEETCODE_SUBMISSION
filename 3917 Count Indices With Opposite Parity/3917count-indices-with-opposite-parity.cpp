class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {
        vector<int>even(nums.size());
        vector<int>odd(nums.size());
        int n = nums.size();
        even[n-1]  = 0;
        odd[n-1] = 0;
        for(int i =n-2; i>=0; i--){
            if(nums[i+1]%2==0){
                even[i] = even[i+1]+1;
                odd[i] = odd[i+1];
            }
              else{
                odd[i] = odd[i+1]+1;
                even[i] = even[i+1];
            }
        }
        vector<int>score(n);
        for(int i=0; i<n; i++){
            if(nums[i]%2==0){
                score[i] = odd[i];
            }
            else{
                score[i] = even[i];
            }
        }
        return score;
        
    }
};
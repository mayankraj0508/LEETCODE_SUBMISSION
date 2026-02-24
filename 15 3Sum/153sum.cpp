class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>>ans;
    sort(nums.begin(),nums.end());
    int i = 0;
    int n = nums.size();
    while( i<n){
        if(i!=0){
        
          while(i<nums.size() && nums[i]==nums[i-1]){
            i++;
          }
        }
        if(i>=nums.size()){
            break;
        }
        int target = -nums[i];
        int j = i+1;
        int k = nums.size()-1;
        while(j<k){
            if(nums[j]+nums[k]==target){
                ans.push_back({nums[i],nums[j],nums[k]});
                int prev1 = nums[j];
                int prev2 = nums[k];
              j++;
              k--;
              while(j<k && nums[j]==prev1){
                j++;
              }
              while(k>j && nums[k]==prev2){
                k--;
              }

            }
            else if(nums[j]+nums[k]<target){
            int prev = nums[j];
            j++;
             while(j<nums.size() && nums[j]==prev){
                j++;
              }
            }
            else{
             int prev = nums[k];
             k--;
             while(k>=0 && nums[k]==prev){
                k--;
              }         

            }
        }
        i++;
    }
    return ans;

    }
};
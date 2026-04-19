class Solution {
public:
    int countElements(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int count = 0;
        int i=0; 
        while(i<nums.size()){
            int dup = 0;
            while(i<nums.size()-1 && nums[i]==nums[i+1]){
                i++;
                dup++;
            }
            
            if(nums.size()-1-i>=k){
                count = count+dup+1;
                
            }
            i++;
        }
        return count;
        
    }
};
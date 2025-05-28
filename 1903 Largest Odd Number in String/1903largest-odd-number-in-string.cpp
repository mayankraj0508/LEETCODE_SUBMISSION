class Solution {
public:
    string largestOddNumber(string nums) {
        int n = nums.size();
        string ans="";
        for(int i = n-1; i>=0;i--){
      
            int a  = nums[i]-'0';
            if(a%2!=0){
               ans = nums.substr(0,i+1);
               return ans;
            }
        }
        return ans;
        
    }
};
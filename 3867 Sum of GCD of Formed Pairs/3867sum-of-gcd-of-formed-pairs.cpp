class Solution {
public:
   long long gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
    long long gcdSum(vector<int>& nums) {
        vector<int>mx(nums.size());
        int ele = INT_MIN;
        int n = nums.size();
        for(int i =0; i<n; i++){
            ele = max(ele,nums[i]);
            mx[i] = ele;
        }
        vector<int>prefixgcd(nums.size());
        for(int i =0; i<n; i++){
            prefixgcd[i] = gcd(nums[i],mx[i]);
        }
        int m = prefixgcd.size();
        sort(prefixgcd.begin(),prefixgcd.end());
        int i = 0;
        int j = prefixgcd.size()-1;
        long long  ans = 0;
        
            
            while(i<j){
                ans = ans+gcd((long long)prefixgcd[i],(long long)prefixgcd[j]);
                i++;
                j--;
                
            }
        return ans;
        

    }
};
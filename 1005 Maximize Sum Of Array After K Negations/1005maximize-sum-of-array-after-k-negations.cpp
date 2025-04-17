class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
         priority_queue<int,vector<int>,greater<int>>pq(nums.begin(),nums.end());
         int n = nums.size();
         int sum  = 0;
         for(int i = 0;i<n; i++){
            sum = sum + nums[i];
         }
            while(k>0){
                int ele = pq.top();
                if(ele==0){
                    break;
                }
                pq.pop();
                sum = sum-ele;
                pq.push(-1*ele);
                sum = sum + (-1*ele);
                k--;

            }
            return sum;


         
        
    }
};
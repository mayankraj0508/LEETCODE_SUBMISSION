class Solution {
public:
    int minDifference(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int ans = INT_MAX;
      //  int  k;
      //  int alpha;
      if(n<=4){
        return 0;
      }
     
    else{
    for(int i=0; i<4; i++){
        for(int j =0; j<=3-i;j++){
            ans  = min(ans,(nums[n-1-i]-nums[j]));

        }
    }
    }
    return ans;

    }
};
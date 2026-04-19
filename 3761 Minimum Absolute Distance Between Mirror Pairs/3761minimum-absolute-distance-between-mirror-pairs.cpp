class Solution {
public:
    int f(int num){
        int rq = 0;
        while(num > 0){
            rq = rq * 10 + (num % 10);
            num /= 10;
        }
        return rq;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int,int> m;
        int ans = INT_MAX;

        for(int i = 0; i < nums.size(); i++){
            if(m.find(nums[i]) != m.end()){
                ans = min(ans, i - m[nums[i]]);
            }

            int rev = f(nums[i]);
            m[rev] = i;  // store reverse
        }

        return (ans == INT_MAX) ? -1 : ans;
    }
};
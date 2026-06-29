class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int>m;
        for(int i =0; i<nums.size(); i++){
            m[nums[i]] =i;
        }
        int a;
        int b;
        for(int i =0; i<nums.size(); i++){
            int des = target-nums[i];
            if(m.find(des)!=m.end()){
                b = m[des];
                a = i;
            
            }
            if(a==i&&a!=b){
                break;
            }

        }
        vector<int>ans = {a,b};
        return ans;
        
    }
};
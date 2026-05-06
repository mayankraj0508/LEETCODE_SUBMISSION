class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        unordered_map<int,int>m;
        int dup = 0;
        for(int i =0; i<nums.size(); i++){
            m[nums[i]]++;
            if(m[nums[i]]==2){
                dup = nums[i];
            }
        }
        int mis = 0;
        for(int i =1; i<=nums.size(); i++){
            if(m.find(i)==m.end()){
                mis = i;
                break;
            }
        }
        return {dup,mis};

        
    }
};
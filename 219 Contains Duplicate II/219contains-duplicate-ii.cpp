class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        int n = nums.size();
        for(int i =0; i<n; i++){
            if(m.find(nums[i])!=m.end()){
                for(auto x:m){
                    if(x.first==nums[i]){
                        if(abs(i-x.second)<=k){
                            return true;
                        }
                        else{
                            m.erase(nums[i]);
                            m[nums[i]] = i;
                            break;
                        }
                    }
                }

            }
            else{
                m[nums[i]] = i;
            }
        }
        return false;

        
    }
};
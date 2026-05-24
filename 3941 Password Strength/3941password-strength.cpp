class Solution {
public:
    int passwordStrength(string nums) {
        unordered_set<char>s;
        for(int i =0; i<nums.size(); i++){
            s.insert(nums[i]);
        }
        int ans = 0;
        for(auto x:s){
            if(x>='a' && x<='z'){
                ans++;
            }
            else if(x>='A' && x<='Z'){
                ans = ans+2;
            }
            else if(x>='0' && x<='9'){
                ans = ans+3;
            }
            else if(x=='!' || x=='@' || x=='#' || x=='$'){
                ans = ans+5;
            }
        }
        return ans;
        
    }
};
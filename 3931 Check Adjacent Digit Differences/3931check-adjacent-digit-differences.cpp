class Solution {
public:
    bool isAdjacentDiffAtMostTwo(string s) {
        for(int i =1; i<s.size(); i++){
            int val1 = s[i]-'0';
            int val2 = s[i-1]-'0';
            int diff = abs(val1-val2);
            if(diff>2){
                return false;
            }
        }
        return true;
        
    }
};
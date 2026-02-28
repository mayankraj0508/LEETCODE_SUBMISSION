class Solution {
public:
    string mergeCharacters(string s, int k) {
        string ans = s;
        
        while(true){
            bool merged = false;
            
            for(int i = 0; i < ans.size(); i++){
                for(int j = i + 1; j < ans.size(); j++){
                    
                    if(ans[i] == ans[j] && j - i <= k){
                        
                        ans.erase(j, 1);   
                        merged = true;
                        break;           
                    }
                }
                if(merged) break;         
            }
            
            if(!merged) break;
        }
        
        return ans;
    }
};
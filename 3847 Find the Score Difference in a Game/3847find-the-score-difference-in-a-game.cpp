class Solution {
public:
    int scoreDifference(vector<int>& nums) {
        char a = '#';
        char b = 'b';
        int scorea = 0;
        int scoreb = 0;
        unordered_map<char,bool>m;
        m[a] = true;
        m[b] = false;
        for(int i =0; i<nums.size(); i++){
            if(nums[i]%2!=0){
                if(m[a] == false){
                    m[a] = true;
                    m[b] = false;
               
                }
                else{
                    m[b] = true;
                    m[a] = false;
                    
                }
            }
            if(i%6==5){
                if(m[a] == false){
                    m[a] = true;
                    m[b] = false;
                   
                }
                else{
                    m[b] = true;
                    m[a] = false;
                  
                }
                
            }
       
                if(m[a]==true){
                    scorea = scorea + nums[i];
                }
                else {
                    scoreb = scoreb+nums[i];
                }
            
            
        }
        return scorea-scoreb;
        
    }
};
class Solution {
public:
    int pivot = INT_MIN;
    int minOperations(string s) {
        sort(s.begin(),s.end());
        int counta =0;
        for(int i =0; i<s.size(); i++){
            if(s[i]=='a'){
                counta++;
            }
        }
        if(counta==s.size()){
            return 0;
        }
        int count =0; 
         for(int i=0; i<s.size()-1; i++){
             if(s[i]!='a'){
             count = count+((int)s[i+1]-(int)s[i]);
             }
        }
        
        count = count+26-((int)s[s.size()-1]-97);
        
        return count;
        
        
    }
};
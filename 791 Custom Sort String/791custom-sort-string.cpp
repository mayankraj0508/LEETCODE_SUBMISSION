class Solution {
public:
    string customSortString(string order, string s) {
        string ans = "";
        
        unordered_map<char,int>m;
        for(int i =0; i<s.size(); i++){
            m[s[i]]++;
        }
        for(int i =0; i<order.size(); i++){
            if(m.find(order[i])!=m.end()){

               while(m[order[i]]!=0){
                ans = ans+order[i];
                m[order[i]]--;
               }
               if(m[order[i]]==0){
                m.erase(order[i]);
               }
            }
        }
        for(int i =0; i<s.size(); i++){
            if(m.find(s[i])!=m.end()){
                ans = ans+s[i];
                m[s[i]]--;
               if(m[s[i]]==0){
                m.erase(s[i]);
               }
            }
        }
        return ans;
        
    }
};
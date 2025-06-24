class Solution {
public:
    vector<vector<string>>groupAnagrams(vector<string>& str) {
        int n = str.size();
        unordered_map<string,vector<string>>m;
        for(int i=0; i<str.size();i++){
            string p = str[i];
            sort(p.begin(),p.end());
            m[p].push_back(str[i]);
        }
        vector<vector<string>>ans;
        for(int i=0; i<str.size();i++){
            string q = str[i];
            sort(q.begin(),q.end());
            if(m.find(q)!=m.end()){
                ans.push_back(m[q]);

                
            }
            m.erase(q);
        
        }
      
      
        return ans;

    
    }
};
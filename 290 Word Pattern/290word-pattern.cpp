class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string>m;
        unordered_map<string,char>l;
       stringstream ss(s);
       vector<string>words;
       string temp;
       while(ss>>temp){
        words.push_back(temp);
       }
       if(words.size()!=pattern.size()){
        return false;
       }
       for(int i =0; i<pattern.size();i++){
        if(m.find(pattern[i])!=m.end()){
            if(words[i]!=m[pattern[i]]){
                return false;
            }

        }
        else{
        m[pattern[i]] = words[i];
        }
       }
       for(int i = 0; i<pattern.size();i++){
        if(l.find(words[i])!=l.end()){
            if(l[words[i]]!=pattern[i]){
                return false;
            }
        }
        else{
            l[words[i]]=pattern[i];
        }

       }
       return true;

        
    }
};
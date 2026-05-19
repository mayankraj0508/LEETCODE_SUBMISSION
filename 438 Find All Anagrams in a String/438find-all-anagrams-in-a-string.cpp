class Solution {
public:
    bool check(int i, int j,string &p, string &s){
        string x = s.substr(i,j-i+1);
        sort(x.begin(),x.end());
        sort(p.begin(),p.end());
        if(x==p){
            return true;
        }
        return false;
    }
    vector<int> findAnagrams(string s, string p) {
        vector<int>ans;
        unordered_map<char,int>m;
        for(int i =0;i<p.size(); i++){
             m[p[i]]++;
        }
       unordered_map<char,int>q;
       for(int i=0; i<p.size(); i++){
          q[s[i]]++;
       }
        if(m==q){
        ans.push_back(0);
       }
       q[s[0]]--;
       if(q[s[0]]==0){
        q.erase(s[0]);
       }
    //    q[s[p.size()]]++;
       int i  = 1;
       int j =  p.size();
       while(j<s.size()){
           q[s[j]]++;
           if(m==q){
            ans.push_back(i);
           }
           q[s[i]]--;
           if(q[s[i]]==0){
            q.erase(s[i]);
           }
           i++;
           j++;
          
       }
       return ans;
        
    }
};
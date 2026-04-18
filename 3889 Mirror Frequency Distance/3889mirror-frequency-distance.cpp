class Solution {
public:
    int mirrorFrequency(string s) {
        unordered_set<char>visited;
        unordered_map<char,int>m1;
        unordered_map<char,int>m2;
        for(int i=0; i<s.size(); i++){
            if(visited.find(s[i])!=visited.end()){
                  m2[s[i]]++;
                continue;
            }
            else{
                if(s[i]>='0' && s[i]<='9'){
                    int pivot = s[i]-'0';
                    char insert = '9'-pivot;
                    visited.insert(insert);
                    m1[s[i]]++;
                } 
                else{
                int pivot = s[i]-'a';
                char insert = 'z'-pivot;
                visited.insert(insert);
                m1[s[i]]++;
                }
            }
            m2[s[i]]++;
            
        }
        int sum = 0;
        for(auto x:m1){
            char p = x.first;
            if(p>='0' && p<='9' ){
                int pivot = p-'0';
                char insert = '9'-pivot;
                if(m2.find(insert)!=m2.end()){
                    sum = sum+abs(x.second-m2[insert]);
                }
                else{
                    sum = sum+x.second;
                }
            }
            else{
            int pivot = p-'a';
            char insert =  'z'-pivot;
            if(m2.find(insert)!=m2.end()){
                sum = sum+abs(x.second-m2[insert]);
            }
            else{
                sum = sum+x.second;
            }   
        }
        }
        return sum;
        
    }
};
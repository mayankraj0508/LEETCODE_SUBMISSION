class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        int n =  arr.size();
        unordered_map<int,int>m;
        unordered_set<int>s;
        for(int i =0; i<n; i++){
            m[arr[i]]++;    
        }
        for(auto p:m){
            int freq = p.second;
             if(s.find(freq)!=s.end()){
                return false;
            }
            s.insert(freq);
        }
        
        return true;

        
    }
};
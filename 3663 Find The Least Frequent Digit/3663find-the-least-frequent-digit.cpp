class Solution {
public:
    int getLeastFrequentDigit(int n) {
        string p   = to_string(n);
        int min_num = INT_MAX;
        int freq = INT_MAX;
        unordered_map<int,int>m;
        int z = p.size();
        for(int i=0; i<z; i++){
            int num = p[i]-'0';
            m[num]++;
        }
         for(auto x:m){
            if(x.second<freq){
                freq = x.second;
                min_num = x.first;
            }
            else if(x.second==freq){
                
                min_num = min(min_num,x.first);
            }
         }
         return min_num;
        
    }
};
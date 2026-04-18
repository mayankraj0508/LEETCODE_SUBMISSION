class Solution {
public:
 
    // void f(int x){
    //     unordered_set<int>visited;
    //     unordered_map<int,int>m;
    //     for(int i=1; i*i*i<=x; i++){
    //         if(visited.find(i)!=visited.end()){
    //             continue;
    //         }
    //         for(int j = 1; j*j*j<=x; j++){
    //             if(visited.find(j)!=visited.end()){
    //                 continue;
    //             }
    //             if(i*i*i + j*j*j==x){
    //                 visited.insert(i);
                    
                    
    //             }
    //         }
    //     }
    //     if(visited.size()>=2){
    //         ans.push_back(x);
    //     }
    // }
    vector<int> findGoodIntegers(int n) {
        vector<int>ans;
        unordered_map<int,int>m;
        for(int i= 1; i*i*i<=n; i++){
            for(int j = i; j*j*j<=n; j++){
                if(i*i*i+j*j*j<=n){
                    m[i*i*i+j*j*j]++;
                    
                    
                }
                else{
                    break;
                }
            }
        }
        for(auto x:m){
            if(x.second>=2){
                ans.push_back(x.first);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
        
        
    }
};
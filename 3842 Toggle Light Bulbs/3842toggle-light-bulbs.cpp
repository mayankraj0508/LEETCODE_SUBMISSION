class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        unordered_map<int,bool>m;
        for(int i =0; i<bulbs.size(); i++){
            if(m.find(bulbs[i])==m.end()){
                m[bulbs[i]] = true;
            }
            else{
               if(m[bulbs[i]]==false){
                   m[bulbs[i]] = true;
               }
                else{
                    m[bulbs[i]] =false;
                }
            }
        }
        vector<int>ans;
        for(auto x: m){
            if(x.second==true){
                ans.push_back(x.first);
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};
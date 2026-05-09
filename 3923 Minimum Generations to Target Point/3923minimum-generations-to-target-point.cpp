class Solution {
public:
    int minGenerations(vector<vector<int>>& points, vector<int>& target) {
        set<vector<int>>visited;
        int ans = 0;
        for(int i =0; i<points.size(); i++){
            visited.insert(points[i]);
            if(points[i][0]==target[0] && points[i][1]==target[1] && points[i][2]==target[2]){
                return 0;
            }
        }
        while(true){
            int n = points.size();
            for(int i = 0; i<n; i++){
              //  int n = points.size();
                for(int j = i+1; j<n; j++){
                    vector<int>a = points[i];
                    vector<int>b = points[j];
                    vector<int>comb(a.size());
                    comb[0]= (a[0]+b[0])/2;
                    comb[1] = (a[1]+b[1])/2;
                    comb[2]  = (a[2]+b[2])/2;
                    
                    if(comb[0]==target[0] && comb[1] ==target[1] && comb[2] ==target[2]){
                        return ans+1;
                    }
                    if(visited.find(comb)==visited.end()){
                    points.push_back(comb);
                        visited.insert(comb);
                    }
                }
               
                

                
            }
            ans++;
             if(points.size()==n){
                    return -1;
                }
           
            
            
        }
        return ans;
    }
};
class Solution {
public:
    vector<string>ans;
    void f(string temp, int n ,int k,int cost, int last){
        if(cost>k){
            return ;
        }
        if(temp.size()>n){
            return ;
        }
        if(temp.size()==n){
            if(cost<=k){
                ans.push_back(temp);
            }
            return ;
        }
        
        if(last==1){
            f(temp+'0',n,k,cost,0);
        }
        else{
            int x = temp.size();
            f(temp+'1',n,k,cost+x,1) ;
            f(temp+'0',n,k,cost,0);
        }

        
    }
    vector<string> generateValidStrings(int n, int k) {
        f("",n,k,0,-1);
        return ans;
        
        
    }
};
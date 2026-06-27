class Solution {
public:
    #define pp pair<int,char>
    void cal(int &x,int &y,char ch){
        if(ch=='R'){
            x++;
        }
        else if(ch=='U'){
            y++;
        }
        else if(ch=='D'){
            y--;
        }
        else{
            x--;
        }
    }
    int maxDistance(string moves) {
        priority_queue<pp>pq;
        unordered_map<char,int>m;
        int blank = 0;
    
        for(int i =0;i<moves.size(); i++){
            if(moves[i]!='R' && moves[i]!='U' && moves[i]!='D' && moves[i]!='L'){
                blank++;
            }
            else{
            m[moves[i]]++;
            }
        }
      
        for(auto x:m){
            pq.push({x.second,x.first});
        }
       
       char c = 'R';
        if(pq.size()){
            c = pq.top().second;
        }
        int x = 0;
        int y = 0;
        for(int i =0; i<moves.size(); i++){
           if(moves[i]!='R' && moves[i]!='U' && moves[i]!='D' && moves[i]!='L'){
                cal(x,y,c);
            }
            else{
                cal(x,y,moves[i]);
            }
        }
        return abs(x)+abs(y);
        
        
        
    }
};
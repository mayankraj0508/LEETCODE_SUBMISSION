class Solution {
public:
    string predictPartyVictory(string s) {
        string l = "Radiant";
        string m = "Dire";
        queue<int>q;
        for(int i =0; i<s.size(); i++){
            q.push(i);
        }
        queue<int>r;
        queue<int>d;
        for(int i =0; i<s.size(); i++){
            if(s[i]=='R'){
                r.push(i);
            }
            else{
                d.push(i);
            }
        }
        while(q.size()>1){
             if(s[q.front()]=='X'){
                q.pop();
            }
           
           else  if(s[q.front()]=='R'){
                //check for vivtory
                if(d.size()==0){
                    return l;
                }
                else{
                    int p = q.front();
                    q.pop();
                    q.push(p);
                    int y = r.front();
                    r.pop();
                    r.push(y);
                    s[d.front()] = 'X';//updating the stringv
                    d.pop();
                }
            }
         
            else{//s[i]=='D
            if(r.size()==0){
                return m;
            }
            else{
                int h = q.front();
                q.pop();
                q.push(h);
                int k = d.front();
                d.pop();
                d.push(k);
                s[r.front()]= 'X';
                r.pop();

            }

            }
            
        }
        if(s[q.front()]=='R'){
            return l;


        }
        else{
            return m;
        }



        
    }
};
class Solution {
public:
    string repeatLimitedString(string s, int repeat) {
        int n = s.size();
        unordered_map<char,int>m;
        string ans = "";
        for(int i =0; i<n; i++){
            m[s[i]]++;
        }
        priority_queue<pair<char,int>>maxheap;
        for(auto x:m){
            maxheap.push({x.first,x.second});
        }
        while(maxheap.size()>0){
            
            char ele = maxheap.top().first;
            int freq = maxheap.top().second;
            int y = min(repeat,freq);
           ans.append(y,ele);
            
            if(freq==y){
                maxheap.pop();
            }

            else{
                if(maxheap.size()==1){
                    break;
                }
                maxheap.pop();
              
               if(maxheap.size()>0){
                
                char ele2 = maxheap.top().first;
                int freq2 = maxheap.top().second;
                int p = min(freq2,repeat);
                maxheap.pop();
                if(p==1){
                ans.append(p,ele2);
                if(freq2==p){
                   // maxheap.pop();
                    if(freq>y){
                     maxheap.push({ele,freq-y});
                    }
                }
                else{
                    if(freq>y){
                    maxheap.push({ele,freq-y});
                    }
                    if(freq2>p){
                    maxheap.push({ele2,freq2-p});
                    }
                }
                }
                else if(p>1){
                    ans = ans + ele2;
                    if(freq>y){
                    maxheap.push({ele,freq-y});
                    }
                    if(freq2>1){
                    maxheap.push({ele2,freq2-1});
                    }


                }
            }

            }
        }
        return ans;
    }
};
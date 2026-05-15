class Solution {
public:
    #define pp pair<int,char>
    string reorganizeString(string s) {
        int sz = s.size();
        unordered_map<char,int>m;
        for(int i =0; i<s.size();  i++){
            m[s[i]]++;
            if( sz%2==0 &&  m[s[i]]>s.size()/2){
                return "";
            }
            else if(sz%2!=0 && m[s[i]]>1+(s.size()/2) ){
                return "";
            }
        }
        priority_queue<pp>pq;
        for(auto x: m ){
            pq.push({x.second,x.first});

        }
        string ans = "";
        while(pq.size()>1){
         char a = pq.top().second;
         int freq1 = pq.top().first;
         pq.pop();
         char b   = pq.top().second;
         int freq2 = pq.top().first;
         pq.pop();
         ans = ans+a;
         freq1--;
         ans = ans+b;
         freq2--;
         if(freq1){
            pq.push({freq1,a});
         }
         if(freq2){
            pq.push({freq2,b});
         }

        }
        if(pq.size()){
            ans = ans+pq.top().second;
        }
        return  ans;

        
    }
};
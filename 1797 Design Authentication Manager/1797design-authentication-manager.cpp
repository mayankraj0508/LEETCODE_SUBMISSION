class AuthenticationManager {
public:
   int t;
   unordered_map<string,int>m;
    AuthenticationManager(int timeToLive) {
        t = timeToLive;
    }
    
    void generate(string tokenId, int currentTime) {
        m[tokenId] = currentTime+t;
        return ;
    }
    
    void renew(string tokenId, int currentTime) {
        if(m.find(tokenId)!=m.end()){
           if(m[tokenId]>currentTime){
            m[tokenId] = t+currentTime;
           }
        }
      return ;
    }
    
    int countUnexpiredTokens(int currentTime) {
         int count = 0;
         for(auto x:m){
            if(x.second>currentTime){
                count++;
            }
         }
         return count;
    }
};

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager* obj = new AuthenticationManager(timeToLive);
 * obj->generate(tokenId,currentTime);
 * obj->renew(tokenId,currentTime);
 * int param_3 = obj->countUnexpiredTokens(currentTime);
 */
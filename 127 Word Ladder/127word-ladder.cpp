class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string>s(wordList.begin(),wordList.end());
        int n = beginWord.size();
        int count =  1;
        if(s.find(endWord)==s.end()){
            return 0;
        }
        queue<string> q;
        q.push(beginWord);
        while(q.size()){
        int sz = q.size();
        for(int i=0; i<sz; i++){
        string p = q.front();
        q.pop();
        for(int k = 0; k<n; k++){
            char l = p[k];
            for(int i =97; i<=123; i++){
                string t = p;
               p[k] = (char)i;
               if(t==p){
                continue;
               }
                if(s.find(p)==s.end()){
                    continue;
                }
                else{
                    if(p==endWord){
                        return count+1;
                    }
                    else{
                        q.push(p);
                        s.erase(p);
                    }
                } 
            }
            p[k] = l;
        }
        }
        count++;
    }
     return 0;
    }
};
class Solution {
public:
    int maximumNumberOfStringPairs(vector<string>& words) {
        unordered_set<string>s;
        for(int i =0; i<words.size();i++){
            s.insert(words[i]);
    }
        int count = 0;
        for(int i =0; i<words.size(); i++){
            string target =words[i];
            reverse(target.begin(),target.end());
            if(words[i]==target) continue;//ager zz pp cc h to unko dekhna hee nahi h
            if(s.find(target)!=s.end()){  
                count++;
                s.erase(words[i]);
            }

        }
        return count;
        
    }
};
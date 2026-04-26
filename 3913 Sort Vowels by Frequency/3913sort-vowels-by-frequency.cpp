class Solution {
public:
    string sortVowels(string s) {
        unordered_map<char,int> freq;
        unordered_map<char,int> firstPos;
        
        string vow = "aeiou";
        
      
        for(int i = 0; i < s.size(); i++){
            if(vow.find(s[i]) != string::npos){
                freq[s[i]]++;
                if(firstPos.find(s[i]) == firstPos.end()){
                    firstPos[s[i]] = i;
                }
            }
        }
        
   
        vector<char> v;
        for(auto &it : freq){
            v.push_back(it.first);
        }
        
        
        sort(v.begin(), v.end(), [&](char a, char b){
            if(freq[a] != freq[b]) return freq[a] > freq[b];
            return firstPos[a] < firstPos[b];
        });
        
        // Step 4: build sorted vowel string
        string sortedVowels = "";
        for(char c : v){
            sortedVowels += string(freq[c], c);
        }
        
        int idx = 0;
        for(int i = 0; i < s.size(); i++){
            if(vow.find(s[i]) != string::npos){
                s[i] = sortedVowels[idx++];
            }
        }
        
        return s;
    }
};
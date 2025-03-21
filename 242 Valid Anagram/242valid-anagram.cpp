class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size()){
            return false;
        }
        // ya to sort kardo fir equate karke dekho 
        //iuisng hashmaps  ye frequency ke sath string ko rkhega 
        unordered_map<char,int>map1;
        unordered_map<char,int>map2;
        for(int i =0; i<s.size(); i++){
            map1[s[i]]++;// frequency with characyer likhn a ka trika
        }
        for(int i =0; i<t.size(); i++){
            map2[t[i]]++;
        }
        for(auto x:map1){
            char ch = x.first;
            int frequency = x.second;
            if(map2.find(ch)!=map2.end()){
                int frequency2 = map2[ch];
                if(frequency!=frequency2){
                    return false;
                }

            }
            else{
                return false;
            }

        }
        return true;


        
    }
};
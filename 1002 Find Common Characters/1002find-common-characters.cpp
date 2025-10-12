class Solution {
public:
    vector<string> commonChars(vector<string>& words) {
        vector<string>ans;
        for(char ch = 'a'; ch<='z';ch++){
            int min_count = INT_MAX;
            for(string s:words){
                int word_count = 0;
                for(char curr:s){
                    if(curr==ch){
                        word_count++;
                    }

                }
                min_count = min(min_count,word_count);

            }
            string temp = "";
            temp = temp+ch;
            for(int i=0; i<min_count; i++){
                 
                ans.push_back(temp);
            }
        }
        return ans;
        
    }
};
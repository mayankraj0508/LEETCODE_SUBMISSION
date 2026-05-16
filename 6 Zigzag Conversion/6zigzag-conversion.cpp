class Solution {
public:
    string convert(string s, int numRows) {

        vector<string>temp(numRows,"");
        int i =0; 
        int idx= 0;
        if(numRows==1){
            return s;
        }
        while(i<s.size()){

            for(int k = idx; k<numRows && i<s.size(); k++){
                temp[k]  = temp[k]+s[i];
                i++;
            }
            idx = numRows-2;
            for(int k =idx; k>=0 && i<s.size(); k--){
                temp[k] = temp[k]+s[i];
                i++;
            }
            idx = 1;
        }
        string ans = "";
        for(int i =0; i<temp.size(); i++){
            ans = ans+temp[i];
        }
        return ans;
    }
};
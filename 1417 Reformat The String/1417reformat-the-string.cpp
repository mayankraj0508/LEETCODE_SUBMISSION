class Solution {
public:
    string reformat(string s) {
        string digits = "";
        string charc ="";
        for(int i=0; i<s.size(); i++){
            if(s[i]>='0' && s[i]<='9'){
                digits = digits+s[i];
            }
            else{
                charc = charc+s[i];
            }
        }
        if(s.size()==1){
            return s;
        }
        string ans = "";
        int i =0; 
        int j = 0;
        if(charc.size()>digits.size()){
        while(i<digits.size() && j<charc.size()){
            ans = ans+charc[j];
            ans = ans+digits[i];
            
            i++;
            j++;
        }
        }
        else{
            while(i<digits.size() && j<charc.size()){
             ans = ans+digits[i];
            ans = ans+charc[j];
           
            i++;
            j++;
        }

        }
        if(j<charc.size()){
            int rem = charc.size()-j;
            if(rem>=2 || !(ans[ans.size()-1]>='0' && ans[ans.size()-1]<='9')){
                return "";
            }
            else{
                ans = ans+charc[j];
                j++;
            }
        }
       if(i<digits.size()){
            int rem = digits.size()-i;
            if(rem>=2 || (ans[ans.size()-1]>='0' && ans[ans.size()-1]<='9')){
                return "";
            }
            else{
                ans = ans+digits[i];
                i++;
            }
        }
        return ans;
           
        
    }
};
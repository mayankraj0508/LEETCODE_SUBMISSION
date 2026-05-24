class Solution {
public:
    bool check(int i, int j, string &s){
         if(s[i]!=s[j]){
            return false;
         }
         else{
            while(i<j){
                if(s[i]!=s[j]){
                    return false;
                }
               i++;
               j--;
            }
           return true;
         }
    }
    string longestPalindrome(string s) {
        int firstidx = -1;
        int lastidx = -1;
        int ans = INT_MIN;
        int  n = s.size();
        for(int i =0; i<n; i++){
            int j = s.size()-1;
            while(j>=i){
                if(s[i]!=s[j]){
                    j--;

                }
                else{
                    if(check(i,j,s)){
                        if(j-i+1>ans){
                            firstidx = i;
                            lastidx = j;
                            ans = max(ans,lastidx-firstidx+1);
                            break;
                        }
                        else{
                            j--;
                        }


                    }
                    else{
                        j--;
                    }
                }
            }
        }
        return s.substr(firstidx,lastidx-firstidx+1);
        
    }
};
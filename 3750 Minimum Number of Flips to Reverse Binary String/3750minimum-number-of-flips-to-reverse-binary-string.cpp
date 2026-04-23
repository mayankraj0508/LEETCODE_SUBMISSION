class Solution {
public:
    int minimumFlips(int n) {
        string s  = "";
        while(n>=1){
            int rem = n%2;
            n = n/2;
            if(rem==0){
                s = '0'+s;
            }
            else{
                s = '1'+s;
            }
        }
        int i = 0;
        int j =s.size()-1;
        int count = 0;
        string t = s;
        reverse(s.begin(),s.end());
        for(int i = 0; i<s.size(); i++){
            if(t[i]!=s[i]){
                count++;
            }
        }
        return count;
        
    }
};
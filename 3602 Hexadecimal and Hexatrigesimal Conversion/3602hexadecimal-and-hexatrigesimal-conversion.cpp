class Solution {
public:
    char f(int a){
        if(a<=9){
            return '0'+a;
        }
        else{
            int b = a-10;
            return 'A'+b;
        }
    }
    string concatHex36(int n) {
        string ans = "";
        int a = n*n;
        int b = n*n*n;
        while(a>0){
            int rem = a%16;
            ans = f(rem)+ans;
            a = a/16;
        }
        string bns = "";
         while(b>0){
            int rem = b%36;
            bns = f(rem)+bns;
            b= b/36;
        }
        ans = ans+bns;
        return ans;
 
    }
};
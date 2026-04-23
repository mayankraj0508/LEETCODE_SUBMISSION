class Solution {
public:
    string addBinary(string a, string b) {
        string ans = "";
        int i = a.size()-1;
        int j = b.size()-1;
        int carry = 0;
        while(i>=0 && j>=0 ){
            char f = a[i];
            char s = b[j];
            if(f=='0' && s=='0'){
                if(carry==1){
                    ans = '1'+ans;
                    carry = 0;
                }
                else{
                ans = '0'+ans;
                }
            }
            else if(f=='1' && s=='0' || f=='0' && s=='1'){
                if(carry==0){
                ans  = '1'+ans;
                }
                else{
                    ans = '0'+ans;
                    carry = 1;
                }
            }
            else {
                if(carry==0){
                ans = '0' +ans;
                carry = 1;
                }
                else{
                    ans = '1'+ans;
                    carry = 1;
                }

            }
            i--;
            j--;
        }
       if(i>=0){
        while(i>=0){
            if(carry==1){
                if(a[i]=='0'){
                    ans = '1'+ans;
                    carry = 0;
                }
                else{
                    ans = '0'+ans;
                    carry = 1;
                }
            }
            else{
                ans = a[i]+ans;
            }
            i--;

        }
       }
     if(j>=0){
        while(j>=0){
            if(carry==1){
                if(b[j]=='0'){
                    ans = '1'+ans;
                    carry = 0;
                }
                else{
                    ans = '0'+ans;
                    carry = 1;
                }
            }
            else{
                ans = b[j]+ans;
            }
            j--;

        }
       }
       if(carry==1){
        ans = '1'+ans;
       }
        return ans;

        
    }
};
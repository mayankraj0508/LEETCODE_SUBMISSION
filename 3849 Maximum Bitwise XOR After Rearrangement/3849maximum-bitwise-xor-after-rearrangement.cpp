class Solution {
public:
    string maximumXor(string s, string t) {
         int count0 = 0;
        int count1 = 0;
        for(int i =0; i<t.size(); i++){
            if(t[i]=='1'){
                count1++;
            }
            else{
                count0++;
            }
        }
        string p;
        for(int i =0; i<s.size(); i++){
            if(s[i]=='0'){
                if(count1>0){
                    count1--;
                    p.push_back('1');
                }
               else if(count0>0){
                   count0--;
                   p.push_back('0');
               }
                else{
                    break;
                }
            }
            else{
                   if(count0>0){
                    count0--;
                    p.push_back('0');
                }
               else if(count1>0){
                   count1--;
                   p.push_back('1');
               }
                else{
                    break;
                }
                
            }
        }
        string ans = "";
        for(int i =0; i<s.size(); i++){
            int a = (int )s[i];
            int b = (int)p[i];
            int an = a^b;
             if(an==0){
                 ans.push_back('0');
             }
            else{
                ans.push_back('1');
            }
           
            
        }
        return ans;
        
    }
};
class Solution {
public:
   void f(int n, vector<int>&bits){
       while(n>0){
          bits.push_back(n%2);
        n = n/2;
       }
       reverse(bits.begin(),bits.end());
   }
    int minBitFlips(int start, int goal) {
        vector<int>bits1;
        vector<int>bits2;
        f(start,bits1);
        f(goal,bits2);
        int count = 0;
        int mx = max(bits1.size(),bits2.size());
        if(mx==bits1.size()){
             int diff = mx-bits2.size();
             for(int i =0; i<mx; i++){
                if(i>=0&&i<diff){

                    if(bits1[i]==1){
                        count++;
                    }
                }
                else{
                if(bits1[i]!=bits2[i-diff]){
                    count++;
                }
                }
             } 

        }
        else{
             int diff = mx-bits1.size();
             for(int i =0; i<mx; i++){
                if(i>=0&&i<diff){

                    if(bits2[i]==1){
                        count++;
                    }
                }
                else{
                if(bits2[i]!=bits1[i-diff]){
                    count++;
                }
                }
             } 


        }
        return count;


        
    }
};
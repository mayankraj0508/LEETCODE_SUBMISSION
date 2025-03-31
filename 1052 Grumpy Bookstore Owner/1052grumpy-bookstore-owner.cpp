class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int result = 0;
        int k = minutes;
        int i =1;
        int j = k;
        int idx = 0;
        int n  = grumpy.size();
        int prevloss = 0;
        for(int i =0; i<k; i++){
            prevloss=prevloss+customers[i];
        }
        int maxloss= prevloss;
        while(j<n){
            int currentloss = prevloss;
            if(grumpy[i-1]==1){
                currentloss=currentloss-customers[i-1];
            } 
            if(grumpy[j]==1){
                currentloss+=customers[j];

            }
            if(currentloss>maxloss){
                
                maxloss = currentloss;
                idx = i;

            }
            prevloss = currentloss;
            i++;
            j++;


        }
        for(int i =idx; i<(idx+k);i++){
            grumpy[i]=0;
        }
        for(int i =0; i<n; i++){
            if(grumpy[i]==0){
                result = result+customers[i];
            }
        }
        return result;

       





        
    }
};
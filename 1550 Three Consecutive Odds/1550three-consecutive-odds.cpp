class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int n = arr.size();
        int count = 0;
        int i = 0;
        while(i<n){
            if(arr[i]%2==0){
                count=0;
                i++;
    
            }
            else{
                count++;
                 i++;


            }
               if(count==3){
            return true;
        }
        }
       
        
     return false;
        



        
        
    }
};
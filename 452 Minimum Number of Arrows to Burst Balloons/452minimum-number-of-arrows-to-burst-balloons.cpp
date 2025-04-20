bool cmp(vector<int>&a,vector<int>&b){
    return a[1]<b[1];
}
class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& arr) {
         sort(arr.begin(),arr.end(),cmp);//end time wis sortingh
        //int minrow = arr[0][0];
        int col = arr[0][1];
        int n = arr.size();
        int count = 0;
        for(int i = 1; i<n; i++){
           
                if(arr[i][0]<=col){//current ka jo row h wo pichle ke column se bada hona chahiye
                    count++;
                }
               else{
                    
                  //  minrow = min(arr[i][0],minrow);
                    col =max(arr[i][1],col);
                  
               }
                

            }
        
        return  n-count;
        
        
    }
};
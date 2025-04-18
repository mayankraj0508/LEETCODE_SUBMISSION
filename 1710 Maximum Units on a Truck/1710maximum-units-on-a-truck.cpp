  bool customcomparator(vector<int>&a,vector<int>&b){
    return a[1]>b[1];
}



class Solution {
  
public:

    int maximumUnits(vector<vector<int>>& arr, int trucksize) {
        sort(arr.begin(),arr.end(),customcomparator);
        int ans = 0;
        for(int i = 0; i<arr.size();i++){
            if(arr[i][0]<=trucksize){
                ans = ans + arr[i][0]*arr[i][1];
                trucksize = trucksize-arr[i][0];
            }
            else{
                ans = ans + trucksize*arr[i][1];
                break;
            }
            if(trucksize==0){
                break;
            }

           
           
           
        }
        return ans;





        
    }
};
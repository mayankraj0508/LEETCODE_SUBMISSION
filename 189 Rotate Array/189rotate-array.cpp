class Solution {
public:
   
    void rotate(vector<int>& v, int k) {
         int n = v.size();
         if(k>n){
            k = k%n;
         }
        /* for(int m = 0; m<k; m++){
            swap(arr[m],arr[n-1]);
            for(int i = n-2; i>=m+1;i--){
                swap(arr[i],arr[i+1]);
            }
         }
         reverse(arr.begin(),arr.begin()+k);*/
         //above aprroach does not work on one case TLE
         //new approach
         reverse(v.begin(),v.end());
         reverse(v.begin(),v.begin()+k);
         reverse(v.begin()+k,v.end());

       
       
       
    
        return;
    }
};
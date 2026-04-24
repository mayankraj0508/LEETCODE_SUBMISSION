class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
      int m = mat.size();
      int n = mat[0].size();
      int lo = 0;
      int hi = m-1;
      int ans = INT_MIN;
      int idx = -1;
     
      while(lo<=hi){
        int mid  = lo+(hi-lo)/2;
        int ele = INT_MIN;
        int idx;
        for(int j = 0; j<n; j++){
            if(mat[mid][j]>ele){
               ele = mat[mid][j];
               idx = j;   
            }
        }
        if(mat.size()==1){
            return {mid,idx};
        }
        if(mid==0){
             if(mat[mid][idx]>mat[mid+1][idx]){
            return {mid,idx};
        }
        else{
            lo = mid+1;
        }

        }
        else if(mid==mat.size()-1){
             if( mat[mid][idx]>mat[mid-1][idx]){
            return {mid,idx};
        }
        else{
            hi = mid-1; 
        }
        }
      else  if(mat[mid][idx]>mat[mid+1][idx] && mat[mid][idx]>mat[mid-1][idx]){
            return {mid,idx};
        }
        else if(mat[mid+1][idx]>mat[mid][idx]){
            lo = mid+1;
        }
        else{
            hi = mid-1;
        }

      }
      return {-1,-1};


        
    }
};
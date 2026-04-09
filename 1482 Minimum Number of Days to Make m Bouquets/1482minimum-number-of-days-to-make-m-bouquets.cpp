class Solution {
public:
    int f(int mid,vector<int>&bloomday,int k){
        int i = 0;
        int ans = 0;
        while(i<bloomday.size()){
            int count = 0;
            if(bloomday[i]<=mid){
            while( i<bloomday.size()-1 && bloomday[i]<=mid && bloomday[i+1]<=mid){
                count++;
                i++;
            }
            count++;
        }
            ans = ans+ count/k;
            i++;

        }
    
        return ans;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int lo = INT_MAX;
        int hi = INT_MIN;
        int n = bloomDay.size();
          if((long long)m*k>n){
            return -1;
        }
        for(int i =0; i<n; i++){
            lo = min(lo,bloomDay[i]);
            hi = max(hi,bloomDay[i]);
        }
        int mid = lo+(hi-lo)/2;
        int ans = -1;
        while(lo<=hi){
             mid = lo+(hi-lo)/2;
           int  calculate = f(mid,bloomDay,k);
           
             if(calculate<m){
                lo = mid+1;
            }
            else{
                ans = mid;
                hi = mid-1;
            }
        }
       
        return ans;
        
        
        
    }
};
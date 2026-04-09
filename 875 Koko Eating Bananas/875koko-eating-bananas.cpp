class Solution {
public:
bool check(int speed,vector<int>& piles, int h){
    long  long count = 0;
    int n = piles.size();
    for(int i =0; i<n; i++){
         if(speed>=piles[i]){
            count  =count+1;
        }
        else if (piles[i]%speed==0){
            count =count+(long long)(piles[i]/speed);
        }
        else{
            count+=(long long)(piles[i]/speed+1);
        }
    }
    if(count>h){
        return false;
    }
    else{
        return true;
    }
    
    

}

    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int a  = INT_MIN;
        int lo = INT_MAX;
        for(int i =0; i<n; i++){
            if(piles[i]>a){
                a = piles[i];

            }
            lo = max(lo,piles[i]);

        }
        int ans;
         lo = 1;
        int hi = a;
        while(lo<=hi){
            int mid = lo+(hi-lo)/2;
            if(check(mid,piles,h)){
                ans = mid;
                hi = mid-1;
                
            }
            else{
                lo = mid+1;
            }
        }
        return ans;
        
    }
};
class Solution {
public:
bool check( int mid,vector<int>& weights, int day){
    int n = weights.size();
    int m =mid;
    int count =0;
    for(int i=0; i<n; i++){
        if(m>=weights[i]){
            m = m-weights[i];
        }
        else{//yaha jab weights ke kam mid hoga tpo next day samaan jaayega
        count++;
        m = mid;
        m = m-weights[i];

        }
        


        
    }
    count  = count+1;
    if(count>day){
        return false;
    }
    else{
        return true;
    }

}
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int max = INT_MIN;
        int sum =0;
        for(int i =0; i<n; i++){
            if(weights[i]>max){
                max  = weights[i];

            }
            sum +=weights[i];

        }
        int lo = max;
        int hi = sum;
        int mincapacity = sum;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(check(mid,weights,days)){
                mincapacity = mid;
                hi = mid-1;
            }
            else{
                lo = mid+1;
            }


        }
        return mincapacity;
        
    }
};
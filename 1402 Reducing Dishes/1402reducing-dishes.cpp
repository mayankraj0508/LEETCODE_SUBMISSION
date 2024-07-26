class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        sort(satisfaction.begin(),satisfaction.end());
        int idx;
        int sum  = 0;
        int n = satisfaction.size();
        vector<int>suf(n);
        for(int i =n-1;i>=0;i--){
            if(i==n-1){
                suf[i] = satisfaction[i];
            }
            else{
            suf[i] = satisfaction[i]+suf[i+1];
            }


        }
        for(int i =0; i<n; i++){
            if(suf[i]>=0){
                idx  = i;
                break;

            }
        }
        int y = n-idx;
        for(int i =1; i<=y; i++){
            sum  = sum+ satisfaction[idx]*i;
            idx++;
        }
        return sum;

        
    }
};
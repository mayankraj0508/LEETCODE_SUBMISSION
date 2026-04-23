class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(),citations.end());
        int n = citations.size();
        int ans = 0;
        for(int i = 0; i<n; i++){
            int number = n-i;
            if(number<=citations[i]){
                ans = n-i;
                break;
            }
            
        }
       
        return ans;
        
    }
};
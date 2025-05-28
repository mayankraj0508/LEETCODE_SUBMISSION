class Solution {
public:
/*int fact(int n){
    if(n==1||n==0){
        return 1;
    }
    return n*fact(n-1);
}*/
    vector<int> getRow(int rowindex) {
        vector<int>ans(rowindex+1) ;
        long long val = 1;
        for(int j = 0; j<=rowindex; j++){
            ans[j] = val;
            val = val *(rowindex-j)/(j+1);
        }
        return ans;
        
    }
};
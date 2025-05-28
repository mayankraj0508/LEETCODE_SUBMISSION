class Solution {
public:
    int matrixScore(vector<vector<int>>& nums) {
        int m = nums.size();
        int n = nums[0].size();
        for(int i=0; i<m; i++){
            if(nums[i][0]==0){
                for(int j =0; j<n;j++ ){
                    if(nums[i][j]==0){
                        nums[i][j]=1;

                    }
                    else{
                        nums[i][j]=0;
                    }
                }

            }
        }
            for(int j =1; j<n;j++ ){
                 int countzero = 0;
                 int countone = 0;
                for(int i =0; i<m; i++){
                   
                    if(nums[i][j]==0){
                        countzero++;
                    }
                 
                }
                    countone = m-countzero;
                    if(countzero>countone){
                        for(int i =0; i<m; i++){
                            if(nums[i][j]==0){
                                nums[i][j]=1;
                            }
                            else{
                                nums[i][j]=0;
                            }
                        }
                    }
            }
        
        int ans = 0;
        for(int i =0; i<m; i++){
            int x = 1;
         //   ans = ans + nums[i][n-1];
            for(int j =n-1; j>=0; j--){

                ans = ans + nums[i][j]*x;
                x = x*2;
            }
        }
        return ans;


        
    }
};
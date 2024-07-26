class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int ans ;
        

        sort(nums.begin(),nums.end());
        int n = nums.size();
        int m = queries.size();
        vector<int>v(n);
        vector<int>k(m);
        v[0] = nums[0];
        
        for(int i =1; i<n; i++){
          
            v[i] = nums[i]+v[i-1];


        }
        for(int i =0; i<m; i++){
            int ans  = 0;
            for(int j= 0; j<n; j++){
                if(v[j]>queries[i]){
                    break;

                }
                else{
                    ans++;
                }

               


                
            }
            k[i] = ans;

            

        }
        return k;
       
       
        
    }
};
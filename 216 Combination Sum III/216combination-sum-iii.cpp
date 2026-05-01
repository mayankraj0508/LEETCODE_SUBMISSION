class Solution {
public:
    vector<vector<int>>ans;
    int val;
    void f(vector<int>&arr, int i, int target,vector<int>temp){
        if(i==arr.size()){
            if(target==0){
                if(temp.size()==val)
                ans.push_back(temp);
                
            }
            return ;
        }
        if(target<0){
            return;
        }
        if(target==0){
            if(temp.size()==val)
            ans.push_back(temp);
            return ;
        }
        temp.push_back(arr[i]);
        f(arr,i+1,target-arr[i],temp);
        if(temp.size())
        temp.pop_back();
        f(arr,i+1,target,temp);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>arr(9);
        val=k;
        for(int i =0; i<9; i++){
            arr[i] = i+1;
        }
        vector<int>temp;
        f(arr,0,n,temp);
          return ans;

      

        
    }
};
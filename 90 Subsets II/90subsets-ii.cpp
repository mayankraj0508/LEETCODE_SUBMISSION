class Solution {
public:
    void subsets(vector<int>&nums,vector<int>&v,vector<vector<int>>&ans,int i,bool flag){
        if(i>=nums.size()){
         ans.push_back(v);
          return ;
        }
        int a = nums[i];
        if(i==nums.size()-1){
            if(flag==true){
                v.push_back(a);
                subsets(nums,v,ans,i+1,true);
                v.pop_back();

            }
            subsets(nums,v,ans,i+1,true);
            return;
        }
        int b = nums[i+1];
        if(a==b){
            if(flag==true){
              v.push_back(a);
              subsets(nums,v,ans,i+1,true);
              v.pop_back();
            }
            subsets(nums,v,ans,i+1,false);
        }
        else{
            if(flag==true){
                v.push_back(a);
                subsets(nums,v,ans,i+1,true);
                v.pop_back();

            }
            subsets(nums,v,ans,i+1,true);
        }  
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int i =0;
        sort(nums.begin(),nums.end());
        vector<int>v;
        vector<vector<int>>ans;
        subsets(nums,v,ans,i,true);
        return ans;

        
    }
};
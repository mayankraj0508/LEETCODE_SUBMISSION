class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
    //     int arr[101];
    //     vector<int>ans =nums;
    //     sort(ans.begin(),ans.end());
    //     arr[ans[0]] =0;
        
    //     for(int i =1; i<ans.size(); i++){
    //          if(ans[i]!=ans[i-1]){
    //             arr[ans[i]] = i;
    //          }
    //          else {
    //             arr[ans[i]] = arr[ans[i-1]];
    //          }
            
    //     }
    //     vector<int>final(ans.size());
    //    for(int i =0; i<nums.size(); i++){
    //     final[i] = arr[nums[i]];
    //    }
      //return final;
      //other method is make array 100 if you see any elements like 8 go to 9th place andn increment it by 1
      //arr[0] = 0 and arr[1] = 0
      // then calculoate prefix sum of it and you willl get ans 
      int arr[102];
      memset(arr,0,sizeof arr);
      for(int i =0; i<nums.size();i++){
        arr[nums[i]+1]++;
      }
      for(int i =1; i<102; i++){
          arr[i] = arr[i]+arr[i-1];
      }
      vector<int>ans(nums.size());
      for(int i =0;i<nums.size(); i++){
        ans[i]= arr[nums[i]];
      }
      return ans;
        
    }
};
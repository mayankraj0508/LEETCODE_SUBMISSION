class Solution {
public:
    int findSpecialInteger(vector<int>& arr) {
        int n =arr.size();
        int ct =n/4+1;   
        //since array is sorted repeating elements will be near to each other 
        //if not sorted then use map instead
        int count = 1;
        int ans;
        for(int i=0; i<arr.size(); i++){
            count=1;
            while(i+1<arr.size()&&arr[i]==arr[i+1]){
                count++;
                i++;
            }
            if(count>=ct){
                ans = arr[i];
                break;
            }
            
        } 
        return ans;
        
    }
};
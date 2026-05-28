class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n =  nums.size();
        vector<int>nge(n);
        stack<int>st;
        for(int i=nums.size()-1; i>=0; i--){
            st.push(nums[i]);
        }
        for(int i=n-1; i>=0; i--){
            while(st.size() && st.top()<=nums[i]){
                st.pop();
            }
            if(st.size()==0){
                nge[i] = -1;
            }
            else{
                nge[i] = st.top();
            }
            st.push(nums[i]);
        }
        return nge;
        
    }
};
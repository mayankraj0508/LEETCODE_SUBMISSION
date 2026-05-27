class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int>st;
        vector<int>ans;
        int n = nums2.size();
        vector<int>nge(n);
        nge[n-1] = -1;
        st.push(n-1);
        for(int i=n-2; i>=0 ; i--){
            while(st.size() && nums2[st.top()]<=nums2[i]){
                st.pop();
            }
            if(st.size()==0){
                nge[i] = -1;
                st.push(i);
            }
            else{
                nge[i] = st.top();
                st.push(i);
            }

        }
        for(int i=0; i<nums1.size(); i++){
            for(int j=0; j<nums2.size(); j++){
                if(nums1[i]==nums2[j]){
                    if(nge[j]==-1){
                        ans.push_back(-1);
                    }
                    else{
                        ans.push_back(nums2[nge[j]]);
                    }
                }
            }
        }
        return ans;

    }
};
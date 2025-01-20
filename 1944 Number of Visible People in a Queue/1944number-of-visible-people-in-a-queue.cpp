class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& arr) {
        int n = arr.size();
        vector<int>ans(n,0);
        stack<int>st;
      
        ans[n-1] = 0;
        st.push(arr[n-1]);
        for(int i = n-2; i>=0; i--){
            int count = 0;
            
            while(st.size()>0 && st.top()<arr[i] ){
                

                st.pop();
                count++;

            }
            if(st.size()>0){
                count++;//aditional increment in count wbhen tehtre is still somr rlement left inm stavkl
            }
            st.push(arr[i]);
            ans[i] = count;
        }
        return ans;
    }
};
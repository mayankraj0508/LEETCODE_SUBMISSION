class Solution {
public:
    int f(vector<int>&arr,int &ans){
           int n = arr.size();
        vector<int>nse(arr.size());
        
        nse[arr.size()-1] = n;
        stack<int>st;
        st.push(n-1);
        for(int i =n-2;i>=0; i--){
            if(st.size()>0&&arr[i]>arr[st.top()]){
                nse[i] = st.top();
            }
            while(st.size()>0&&arr[i]<=arr[st.top()]){
                st.pop();
            }
            if(st.size()==0){
                nse[i] =n;
            }
            else{
                nse[i] = st.top();
            }
            st.push(i);
        }
        vector<int>pse(n);
         stack<int>rt;
         rt.push(0);
         pse[0] =-1;
         for(int i =1; i<n;i++){
           if(rt.size()>0&&arr[i]>arr[rt.top()]){
            pse[i] = rt.top();
           }
           while(rt.size()>0&&arr[i]<=arr[rt.top()]){
            rt.pop();
           }
           if(rt.size()==0){
            pse[i] = -1;
           }
           else{
            pse[i] =rt.top();
           }
           rt.push(i);
         }
       
         for(int i=0; i<n; i++){
            ans = max(ans,arr[i]*(nse[i]-pse[i]-1));
         }
         return ans;

    }
    int maximalRectangle(vector<vector<char>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();
        int ans = INT_MIN;
     
        vector<int>input(n);
        for(int j = 0; j<n; j++){
            if(matrix[0][j]=='1'){
                input[j] = 1;
            }
            else{
                 input[j] = 0;
            }
            
        }
         ans = f(input,ans);
        for(int i =1; i<m; i++){
            for(int j =0; j<n; j++){
              if(matrix[i][j]=='0'){
                input[j] = 0;
              }
              else{
                input[j] = input[j]+1;
              }
            }
            ans = max(ans,f(input,ans));
        }
        return ans;



    }
};
class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        stack<int>st;
        for(int i =0; i<arr.size(); i++){
           st.push(arr[i]);
        }
        stack<int>rt;
        while(st.size()>0){
            rt.push(st.top());
            st.pop();

        };
        int i =0;
        while(i<arr.size()&&rt.size()!=0){
            if(rt.top()==0){
                arr[i] = 0;
                if(i+1<arr.size()){
                arr[i+1] =0;
                }
                i=i+2;
            }
            else{
                arr[i] =rt.top();
                i++;
            }
  
            
            rt.pop();

        }
        
    }
};
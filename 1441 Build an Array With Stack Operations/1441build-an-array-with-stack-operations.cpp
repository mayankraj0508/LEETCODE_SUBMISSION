class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string>ans;
        int k = 0;
        stack<int>st;
        for(int i =1; i<=n; i++){
            if(k>=target.size()){
                break;
            }
            if(i==target[k]){
                st.push(i);
                ans.push_back("Push");
                k++;
            }
            else{
                ans.push_back("Push");
                ans.push_back("Pop");
            }
        }
        return ans;
        
        
    }
};
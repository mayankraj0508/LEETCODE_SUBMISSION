// class Solution {
// public:
//     bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {       int i,j =0;
//     stack<int>st;
//         while(i<pushed.size()&&j<popped.size()){
//             while(i<pushed.size()&&j<popped.size()){
//                 st.push(pushed[i]);
//                 if(pushed[i]==popped[j]){
//                     i++;
//                     break;
//                 }
//                 i++;
//             }
//             while(st.size()>0&&st.top()==popped[j]){
//                 st.pop();
//                 j++;
//             }
//         }
//         for(int i =j; i<popped.size(); i++){
//             if(st.size()>0&&st.top()==popped[i]){
//                 st.pop();
//             }
//         }
//         if(st.size()==0){
//             return true;
//         }
//         return false;
//     }
// };
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int j = 0; 
        
        for (int x : pushed) {
            st.push(x);
    
            while (!st.empty() && st.top() == popped[j]) {
                st.pop();
                j++;
            }
        }
        
        return st.empty();
    }
};
class Solution {
public:

    int removeDuplicates(vector<int>& arr) {
        
      
      /* int i = 0; 
       int j = 1;
       int count = 0;
       ans.push_back(arr[i]);
       while(j<n){
        if(arr[i]==arr[j]){
           // ans.push_back(arr[i]);
            while(arr[i]==arr[j]){
                count++;
                i++;
                j++;
            }
            ans.push_back(arr[j]);
        }
        else{
           

            i++;
            j++;
          // ans[i-1] = arr[i];
          if(i!=0&&arr[i]!=arr[i-1]){
          ans.push_back(arr[i]);
          }
        }
       }
       int p = sizeof(ans)/sizeof(ans[0]);
       for(int i =0; i<p; i++){
        arr[i] = ans[i];
       }*/
        int n = arr.size();
       vector<int>ans;
      unordered_map<int,int>m;
       for(int i =0; i<n; i++){
        m[arr[i]]++;
       }
       for(int i=0; i<n; i++){
        if(m.find(arr[i])!=m.end()){
            ans.push_back(arr[i]);
            m.erase(arr[i]);
        }

       }
       int p = ans.size();
       for(int i=0; i<p; i++){
        arr[i] = ans[i];
       }
       
      
       return p ;
  
        


        
    }
};
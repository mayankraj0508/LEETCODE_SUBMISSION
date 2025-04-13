class Solution {
public:
typedef pair<int,pair<int,int>>pip;
    vector<int> smallestRange(vector<vector<int>>& arr) {
        // priority_queue<int,vector<int>,greater<int>>minheap;
        priority_queue<pip,vector<pip>,greater<pip>>minheap;
       //minrow
      // pair<int,pair<int,int>>p = {} p
      int mx= INT_MIN;
      for(int m =0; m<arr.size();m++){
            mx = max(mx,arr[m][0]);
            minheap.push({arr[m][0],{m,0}});
            
      }
      int mn = minheap.top().first;
      int start = mn;
      

      int end =  mx;
      while(true){
     // int min  = minheap.top().first;
      int row = minheap.top().second.first;//minrow
     int col = minheap.top().second.second;//mincolo
      minheap.pop();
      if(col==arr[row].size()-1){
        break;
      }
      else{
      minheap.push({arr[row][col+1],{row,col+1}});
      }
      mx = max(mx,arr[row][col+1]);
      mn = minheap.top().first;
      if(mx-mn<end-start){
        start = mn;
        end = mx;
      }





      }
      return {start,end};

      


        
    }
};
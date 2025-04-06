class Solution {
public:
    int lastStoneWeight(vector<int>& arr) {
        int n = arr.size();
        priority_queue<int>pq;
        for(int i =0; i<n; i++){
            pq.push(arr[i]);
        }
        while(pq.size()>=2){
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            int diff = a-b;
            pq.push(diff);

        }
        if(pq.size()==0){
            return 0;
        }
        return pq.top();

        
    }
};
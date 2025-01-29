class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        sort(deck.begin(),deck.end());
        int n = deck.size();
        vector<int>ans(n);
        queue<int>q;
        for(int i =0; i<n; i++){
            q.push(i);
        }
        for(int i =0; i<n; i++){
            int idx = q.front();
            q.pop();
            ans[idx] = deck[i];
            int y = q.front();
            q.pop();
            q.push(y);

        }
  
        return ans;
    
        
    }
};
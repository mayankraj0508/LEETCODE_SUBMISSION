class Solution {
public:
    string frequencySort(string s) {
        int n = s.size();
        string ans = "";
        unordered_map<char,int>m;
        for(int i =0; i<n; i++){
            m[s[i]]++;
        }
        priority_queue<pair<int,char>>maxheap;
        for(auto x:m){
            maxheap.push({x.second,x.first});
        }
        while(maxheap.size()>0){
            int no = maxheap.top().first;
            char ch = maxheap.top().second;
           ans.append(no,ch);
            maxheap.pop();
        }
        return ans;

      
    }
};
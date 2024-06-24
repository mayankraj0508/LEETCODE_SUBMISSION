class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        long long  count = 0;
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        long long  a = g.size();
        long long  b = s.size();
        int i =0;
        int j =0;
        while(i<a && j<b){
            if(g[i]<=s[j]){
                count++;
                i++;
                j++;
            }
            else{
                j++;
            }
        }

         return count;
        
    }
};
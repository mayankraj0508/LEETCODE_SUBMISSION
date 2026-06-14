class Solution {
public:
    long long maxRatings(vector<vector<int>>& units) {
        int m = units.size(), n = units[0].size();
        
        for (auto& row : units)
            sort(row.begin(), row.end());
        
        sort(units.begin(), units.end()); 
        
        if (m == 1 || n == 1) {

            long long ans = 0;
            for (auto& row : units) ans += row[0];
            return ans;
        }
        
   
        long long caseA = units[0][0];
        for (int i = 1; i < m; i++)
            caseA += units[i][1];
  
        int best_t = 1;
        for (int t = 2; t < m; t++)
            if (units[t][1] < units[best_t][1]) best_t = t;
        
        long long caseB = units[0][1]; 
        for (int i = 1; i < m; i++)
            caseB += (i == best_t) ? (long long)units[0][0] : (long long)units[i][1];
        
        return max(caseA, caseB);
    }
};
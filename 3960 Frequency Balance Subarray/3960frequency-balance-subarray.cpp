class Solution {
public:
    int getLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;
        
        for (int i = 0; i < n; i++) {
            unordered_map<int,int> freq;
            unordered_map<int,int> fof;
            int maxFreq = 0;
            
            for (int j = i; j < n; j++) {
                int x = nums[j];
                
                if (freq[x] > 0) {
                    fof[freq[x]]--;
                    if (fof[freq[x]] == 0) fof.erase(freq[x]);
                }
                freq[x]++;
                fof[freq[x]]++;
                maxFreq = max(maxFreq, freq[x]);
                
                int distinct = (int)freq.size();
                bool isValid = false;
                
                // Case 1: only one distinct element
                if (distinct == 1) {
                    isValid = true;
                }
                // Case 2: exactly two freq levels, max = 2 * other
                else if (fof.size() == 2 && maxFreq % 2 == 0) {
                    int half = maxFreq / 2;
                    if (fof.count(maxFreq) && fof.count(half)) {
                        isValid = true;
                    }
                }
                
                if (isValid) ans = max(ans, j - i + 1);
            }
        }
        return ans;
    }
};
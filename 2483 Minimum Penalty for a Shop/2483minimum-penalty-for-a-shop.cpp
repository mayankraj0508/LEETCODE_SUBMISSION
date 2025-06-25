class Solution {
public:
    int ballasuf(char ch) {
        return ch == 'Y' ? 1 : 0; 
    }

    int ballapre(char ch) {
        return ch == 'N' ? 1 : 0;
    }

    int bestClosingTime(string customers) {
        int n = customers.size();
        vector<int> pre(n + 1, 0); 
        vector<int> suf(n + 1, 0);  

       
        for (int i = 0; i < n; i++) {
            pre[i + 1] = pre[i] + ballapre(customers[i]);
        }

 
        for (int i = n - 1; i >= 0; i--) {
            suf[i] = suf[i + 1] + ballasuf(customers[i]);
        }

       
        int minPenalty = INT_MAX;
        int bestHour = 0;

        for (int i = 0; i <= n; i++) {
            int totalPenalty = pre[i] + suf[i];
            if (totalPenalty < minPenalty) {
                minPenalty = totalPenalty;
                bestHour = i;
            }
        }

        return bestHour;
    }
};

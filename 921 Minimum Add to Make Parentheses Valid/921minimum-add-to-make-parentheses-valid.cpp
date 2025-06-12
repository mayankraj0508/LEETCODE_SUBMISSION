class Solution {
public:
    int minAddToMakeValid(string s) {
        int count = 0; // Tracks unmatched '('
        int move = 0;  // Tracks unmatched ')'

        for (char ch : s) {
            if (ch == '(') {
                count++;  // Open one more bracket
            } else if (ch == ')') {
                if (count > 0) {
                    count--;  // Match with an open bracket
                } else {
                    move++;  // Need an extra '('
                }
            }
        }

        return count + move;
    }
};
class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        int i = 0;
        int j = s.size() - 1;
        while (i <= j) {
            if (s[i] == x && s[j] == y) {
                swap(s[i], s[j]);
                i++;
                j--;
            } else if (s[i] == x && s[j] != y) {
                j--;
            } else if (s[i] != x && s[j] == y) {
                i++;
            } else {
                i++;
                j--;
            }
        }
        return s;
    }
};
class Solution {
public:
    void f(int n, vector<string>& ans, string s, int size) {
        if (size == n) {
            ans.push_back(s);
            return;
        }
        if (s == "") {
            f(n, ans, s + '0', size + 1);
            f(n, ans, s + '1', size + 1);
        } else {
            if (s[s.size() - 1] == '0') {
                f(n, ans, s + '1', size + 1);
            } else {
                f(n, ans, s + '0', size + 1);
                f(n, ans, s + '1', size + 1);
            }
        }
    }
    vector<string> validStrings(int n) {
        vector<string> ans;
        f(n, ans, "", 0);
        return ans;
    }
};
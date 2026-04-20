

class Solution {
public:
    vector<string> ans;

    void solve(int idx, string &digits, string &current, vector<string> &mapping) {
    
        if (idx == digits.size()) {
            ans.push_back(current);
            return;
        }

        string letters = mapping[digits[idx] - '0'];

        for (char ch : letters) {
            current.push_back(ch);             
            solve(idx + 1, digits, current, mapping); 
            current.pop_back();                
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        vector<string> mapping = {
            "", "", "abc", "def", "ghi",
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        string current = "";
        solve(0, digits, current, mapping);

        return ans;
    }
};
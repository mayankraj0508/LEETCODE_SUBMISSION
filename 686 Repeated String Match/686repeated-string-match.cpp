class Solution {
public:
    long long powmod(long long a, int b) {
        if (b == 0) return 1;
        long long half = powmod(a, b / 2);
        if (b % 2 == 0) return half * half;
        return a * half * half;
    }

    long long hashString(const string& s) {
        long long sum = 0;
        int m = s.size();
        for (int i = 0; i < m; i++) {
            int asc = (int)s[i] - 'a' + 1;
            sum += asc * powmod(26, m - 1 - i);
        }
        return sum;
    }

    int repeatedStringMatch(string a, string b) {
        int n = a.size(), m = b.size();

        string repeated = a;
        int count = 1;

        // Repeat a enough times so that length >= b.size()
        while (repeated.size() < m) {
            repeated += a;
            count++;
        }

        // Check if b is substring
        if (repeated.find(b) != string::npos) return count;

        // Sometimes b may overlap with next repeat
        repeated += a;
        count++;
        if (repeated.find(b) != string::npos) return count;

        return -1;
    }
};

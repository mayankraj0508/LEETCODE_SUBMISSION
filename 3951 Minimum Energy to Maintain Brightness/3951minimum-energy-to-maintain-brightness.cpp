class Solution {
public:
    long long minEnergy(int n, int brightness, vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());

        long long activeTime = 0;

        long long l = intervals[0][0];
        long long r = intervals[0][1];

        for (int i = 1; i < intervals.size(); i++) {
            long long nl = intervals[i][0];
            long long nr = intervals[i][1];

            if (nl <= r + 1) {
                r = max(r, nr);
            } else {
                activeTime += (r - l + 1);
                l = nl;
                r = nr;
            }
        }

        activeTime += (r - l + 1);

        long long bulbs = (brightness + 2) / 3;

        return bulbs * activeTime;
    }
};
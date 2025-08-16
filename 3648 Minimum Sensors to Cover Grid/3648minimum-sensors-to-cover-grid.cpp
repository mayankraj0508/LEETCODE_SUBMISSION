class Solution {
public:
    int minSensors(int n, int m, int k) {
        int cover = 2 * k + 1; // side length of square covered by one sensor
        int sensors_row = (n + cover - 1) / cover; // ceil(n / cover)
        int sensors_col = (m + cover - 1) / cover; // ceil(m / cover)
        return sensors_row * sensors_col;
    }
};

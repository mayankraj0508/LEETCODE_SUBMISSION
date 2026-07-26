class Solution {
public:
    int largestInteger(int n, int s) {
        if(s==0){
            return 0;
        }
          if (s == 0)
            return (n == 1 ? 0 : -1);

        if (s > 9 * n)
            return -1;

        string  p  = "";

        for (int i = 0; i < n; i++) {
            int num = min(9, s);
            p += char('0' + num);
            s = s-num;
        }

        return stoi(p);
        
    }
};
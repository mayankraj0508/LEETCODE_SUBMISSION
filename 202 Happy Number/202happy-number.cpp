class Solution {
public:
int helper(int n){
    int sum = 0;
    while(n>0){
        int rem = n%10;
        n = n/10;
        sum = sum + rem*rem;
    }
    return sum;
    
}
    bool isHappy(int n) {
        unordered_map<int,int>m;
        while(m.find(n)==m.end()){
            m[n]++;
            n = helper(n);
            if(n==1){
                return true;
            }
          //  m.insert(n);
        }
        return false;
       
        
    }
};
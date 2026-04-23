class Solution {
public:
    int f(string s){
        if(s.size()<=2){
            return 0;
        }
        int count = 0;
        for(int i = 1; i<s.size()-1; i++){
            int x = s[i]-'0';
            int prev = s[i-1]-'0';
            int next = s[i+1]-'0';
            if((x>next && x>prev )|| (x<next && x<prev)){
                count++;
            }
        }
        return count;
    }
    int totalWaviness(int num1, int num2) {
        int count = 0;
        for(int i=num1; i<=num2; i++){
            string s = to_string(i);
            count  = count+f(s);
            
        }
        return count;
        
    }
};
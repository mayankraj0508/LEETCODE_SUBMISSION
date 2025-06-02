class Solution {
public:
int val(char ch){
    int a;
    if(ch=='I'){
        a = 1;
        return a;
    }
     if(ch=='V'){
        a = 5;
        return a;
    }
     if(ch=='X'){
        a = 10;
         return a;
    }
     if(ch=='L'){
        a = 50;
         return a;
    }
     if(ch=='C'){
        a = 100;
         return a;
    }
     if(ch=='D'){
        a = 500;
         return a;
    }
     if(ch=='M'){
        a = 1000;
        return a;
    }
    return a;

}
    int romanToInt(string s) {
        int n = s.size();
        int ans = 0;
        int i =0;
        while(i<n-1){
            if(val(s[i])>=val(s[i+1])){
            ans = ans + val(s[i]);
            i++;
            }
            else{
                ans = ans + val(s[i+1])-val(s[i]);
                i = i+2;
            }
        }
        if(i==n-1){
        ans = ans + val(s[n-1]);
        }
        return ans;
        
    }
};
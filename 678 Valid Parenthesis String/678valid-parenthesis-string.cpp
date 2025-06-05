class Solution {
public:
    bool checkValidString(string s) {
        int min = 0;
        int max = 0;
        int n = s.size();
        for(int i =0;i<n;i++){
            if(s[i]=='('){
                min++;
                max++;
            }
            else if(s[i]==')'){
                min--;
                max--;
            }
            else{
                //star rhega fir ya tio ()"" ho sktya h ,maylabn ya to 1 -1,0 
                //range nme maiumum me ek badh jaaega and min me ek kam agarmkn mkam hoga fir usko zero kar do as minun s=   feaible nagi h 
                min = min-1;
                max = max + 1;
            }
            if(min<0){
                min =0;
            }
            if(max<0){
                return false;
            }
        }
        if(min>0){
            return false;
        }
        return true;


       
    }
};
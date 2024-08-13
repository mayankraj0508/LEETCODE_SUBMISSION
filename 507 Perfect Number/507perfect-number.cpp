class Solution {
public:
bool isprime(int n){
    if(n==1){
        return false;
    }
    for(int i =2; i<sqrt(n);i++){
        if(n%i==0){
            return false;
        }
    }
    return true;
}


    bool checkPerfectNumber(int num) {
        int sum = 0;
        vector<int>factors;

        for(int i = 2; i<=sqrt(num);i++){
           
            if(num%i==0){
            
                factors.push_back(i);
                
                 factors.push_back(num/i);
                
               

            }
        }
        factors.push_back(1);

       
        for(int i =0; i<factors.size();i++){
            sum  = sum + factors[i];
        }
        if(num==1){
            return false;
        }
        if(sum == num){
            return true;
        }
        else{
            return false;
        }
     
        
    }
};
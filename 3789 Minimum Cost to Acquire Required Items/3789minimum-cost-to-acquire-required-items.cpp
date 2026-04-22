class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long ans = 0;
         while(need1>0 || need2>0){
            if(need1==0){
                if(need2==0){
                    break;
                }
                else{
                    ans = ans+min((long long)costBoth*need2,(long long)cost2*need2);
                    need2 = 0;
                    break;
                }
            }
               if(need2==0){
                if(need1==0){
                    break;
                }
                else{
                    ans = ans+min((long long)costBoth*need1,(long long)cost1*need1);
                    need1 = 0;
                    break;
                }
            }
            else{
               if(need1==need2){
                 ans = ans+ min((long long)need1*cost1+(long long )need2*cost2,(long long)costBoth*need1);
                 break;
               }
               else{
                if(need1<need2){

                   //case 1
                   long long  c1 =(long long ) need1*costBoth + (long long)(need2-need1)*cost2;
                   long long  c2 =(long long) need1*costBoth +(long long)(need2-need1)*costBoth;
                   long long  c3 =(long long) need1*cost1 +(long long )need2*cost2;
                   ans = ans+ min({c1,c2,c3});
                   break;

                }
                else{
                long long  c1 = (long long)need2*costBoth + (long long)(need1-need2)*cost1;
                 long long  c2 = (long long )need2*costBoth +(long long)(need1-need2)*costBoth;
                   long long c3 = (long long)need1*cost1 +(long long)need2*cost2;
                   ans = ans+ min({c1,c2,c3});
                   break;
                }
               }
            }
            
         }
        return ans;
    }
};
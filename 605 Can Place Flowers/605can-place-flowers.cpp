class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        int sz = flowerbed.size();
        if(sz==1){
            if(flowerbed[0]==0){
                count++;
                return count>=n;
            }
        }
        for(int i =0; i<sz; i++){
            if(i==0 && flowerbed[0]!=1){
                if(flowerbed[i+1]!=1){
                    count++;
                    flowerbed[0] = 1;
                }
            }
           else if(i==sz-1 && flowerbed[i]!=1){
                if(flowerbed[i-1]!=1){
                    flowerbed[i] = 1;
                    count++;

                }
            }

           else  if(flowerbed[i]==0 && flowerbed[i-1]!=1 && flowerbed[i+1]!=1){
                count++;
                flowerbed[i] = 1;
    
            }
        }
        return count>=n;
        
    }
};
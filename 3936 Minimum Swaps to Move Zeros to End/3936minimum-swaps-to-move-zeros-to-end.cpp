class Solution {
public:
    int minimumSwaps(vector<int>& funnyPunnyArray) {
        
        int zeroKaStock = 0;
        
        for(int itemBabu : funnyPunnyArray){
            if(itemBabu == 0){
                zeroKaStock++;
            }
        }

        int mastAnswer = 0;

        for(int i = funnyPunnyArray.size() - zeroKaStock; 
            i < funnyPunnyArray.size(); i++){
            
            if(funnyPunnyArray[i] != 0){
                mastAnswer++;
            }
        }

        return mastAnswer;
    }
};
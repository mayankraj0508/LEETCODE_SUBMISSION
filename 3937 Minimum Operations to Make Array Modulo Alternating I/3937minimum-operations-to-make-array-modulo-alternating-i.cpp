class Solution {
public:
    
    int kaandCost(int rem, int target, int k){
        int seedhaPanga = abs(rem - target);
        int golGolPanga = k - seedhaPanga;

        return min(seedhaPanga, golGolPanga);
    }

    int minOperations(vector<int>& funnyModuloArray, int k) {
        
        int mastAnswer = INT_MAX;

        for(int evenKaRemainder = 0;
            evenKaRemainder < k;
            evenKaRemainder++) {

            for(int oddKaRemainder = 0;
                oddKaRemainder < k;
                oddKaRemainder++) {

                if(evenKaRemainder == oddKaRemainder){
                    continue;
                }

                int totalBakchodiCost = 0;

                for(int i = 0; i < funnyModuloArray.size(); i++){

                    int currentRemainder =
                        funnyModuloArray[i] % k;

                    if(i % 2 == 0){
                        totalBakchodiCost +=
                            kaandCost(
                                currentRemainder,
                                evenKaRemainder,
                                k
                            );
                    }
                    else{
                        totalBakchodiCost +=
                            kaandCost(
                                currentRemainder,
                                oddKaRemainder,
                                k
                            );
                    }
                }

                mastAnswer =
                    min(mastAnswer, totalBakchodiCost);
            }
        }

        return mastAnswer;
    }
};
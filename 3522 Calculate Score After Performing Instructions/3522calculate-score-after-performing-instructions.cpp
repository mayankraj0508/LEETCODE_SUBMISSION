class Solution {
public:
    long long calculateScore(vector<string>& instructions, vector<int>& values) {
        long long  score = 0;
        int i =0;
        unordered_set<int>visited;
        while(i<instructions.size() && i>=0){
            if(visited.find(i)!=visited.end()){
                break;
            }
            visited.insert(i);
            if(i<0 || i>=instructions.size()){
                break;
            }
            if(instructions[i]=="add"){
                score = score + values[i];
                i++;
            }
            else{
                i = i+values[i];
            }
        }
        return score;
        
        
    }
};
class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {
        int score = 0;
        int counter = 0;
        int n = events.size();
        for(int i= 0; i<n; i++){
            if(counter==10){
                break;
            }
            if(events[i]=="0" || events[i]=="1" || events[i]=="2" || events[i]=="3" || events[i]=="4" || events[i]=="5" || events[i]=="6"){
               int n = stoi(events[i]);
                score = score+n;
                
            }
            else if(events[i]=="WD" || events[i]=="NB"){
                score++;
            }
            else if(events[i]=="W"){
                counter++;
            }
            else{
                continue;
            }
            
        }
        return {score,counter};
        
    }
};
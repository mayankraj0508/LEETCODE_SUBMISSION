class Solution {
public:
    string tictactoe(vector<vector<int>>& move) {
        vector<vector<string>>grid;
        grid.resize(3,vector<string>(3," "));
        for(int i =0; i<move.size(); i++){
            
            if(i%2==0){
                grid[move[i][0]][move[i][1]] = "X";
                int count = 0;
                for(int k =0; k<3; k++){
                    if(grid[k][move[i][1]]=="X"){
                        count++;
                    }
                }
                if(count==3){
                    return "A";
                }
                count = 0;
                   for(int j =0; j<3; j++){
                    if(grid[move[i][0]][j]=="X"){
                        count++;
                    }
                }
                if(count==3){
                    return "A";
                }
                count = 0;
                for(int k =0; k<3; k++){
                    for(int l =0; l<3; l++){
                        if(k+l==2){
                            if(grid[k][l]=="X")
                            count++;
                        }
                    }
                }
                if(count==3){
                    return "A";
                }
                count = 0;
                   for(int k =0; k<3; k++){
                    for(int l =0; l<3; l++){
                        if(k==l){
                            if(grid[k][l]=="X")
                            count++;
                        }
                    }
                }
                if(count==3){
                    return "A";
                }
             
             }
             else {
                grid[move[i][0]][move[i][1]]  = "0";
                int count = 0;
                for(int k =0; k<3; k++){
                    if(grid[k][move[i][1]]=="0"){
                        count++;
                    }
                }
                if(count==3){
                    return "B";
                }
                count = 0;
                   for(int j =0; j<3; j++){
                    if(grid[move[i][0]][j]=="0"){
                        count++;
                    }
                }
                if(count==3){
                    return "B";
                }
                count = 0;
                for(int k =0; k<3; k++){
                    for(int l =0; l<3; l++){
                        if(k+l==2){
                            if(grid[k][l]=="0")
                            count++;
                        }
                    }
                }
                if(count==3){
                    return "B";
                }
                count = 0;
                   for(int k =0; k<3; k++){
                    for(int l =0; l<3; l++){
                        if(k==l){
                            if(grid[k][l]=="0")
                            count++;
                        }
                    }
                }
                if(count==3){
                    return "B";
                }

             }

        }
        for(int i =0; i<3; i++){
            for(int j = 0;  j<3; j++){
                if(grid[i][j]==" "){
                    return "Pending";
                }
            }
        }

        return "Draw";
        
        
    }
};
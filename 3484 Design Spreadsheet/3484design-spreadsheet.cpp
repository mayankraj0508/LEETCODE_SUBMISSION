class Spreadsheet {
public:
    vector<vector<int>>grid;
    Spreadsheet(int rows) {
        grid.resize(rows,vector<int>(26,0));
        
        
    }
    
    void setCell(string cell, int value) {
        char ch1 = cell[0];
        int col = ch1-'A';
        int j = cell.size()-1;
        int num = 0;
        int prev = 1;
        while(j>=1){
            int k = cell[j]-'0';
            num = num+k*prev;
            prev = prev*10;
            j--;
        }
        grid[num-1][col] = value;
        
        
    }
    
    void resetCell(string cell) {
         char ch1 = cell[0];
        int col = ch1-'A';
        int j = cell.size()-1;
        int num = 0;
        int prev = 1;
        while(j>=1){
            int k = cell[j]-'0';
            num = num+k*prev;
            prev = prev*10;
            j--;
        }
        grid[num-1][col] = 0;
        
        
    }
    
    int getValue(string formula) {
        int i = 1;
        int j = formula.size()-1;
        string s1 = "";
        string s2 = "";
        while(formula[i]!='+'){
            s1 = s1+formula[i];
            i++;
        }
        while(formula[j]!='+'){
            s2 = formula[j]+s2;
            j--;
        }
        bool flag1 = false;
        bool flag2  = false;
        if(s1[0]>='0' && s1[0]<='9'){
            flag1  = true;
        }
        if(s2[0]>='0' && s2[0]<='9'){
            flag2 = true;
        }
        if(flag1 && flag2){
        int j = s1.size()-1;
        int num = 0;
        int prev = 1;
        while(j>=0){
            int k = s1[j]-'0';
            num = num+k*prev;
            prev = prev*10;
            j--;
        }
         j = s2.size()-1;
       int  num2 = 0;
         prev = 1;
        while(j>=0){
            int k = s2[j]-'0';
            num2 = num2+k*prev;
            prev = prev*10;
            j--;
        }
            return num+num2;
            
        }
        else if(flag1 && !flag2){
        int j = s1.size()-1;
        int num = 0;
        int prev = 1;
        while(j>=0){
            int k = s1[j]-'0';
            num = num+k*prev;
            prev = prev*10;
            j--;
        }
         char ch1 = s2[0];
        int col = ch1-'A';
         j = s2.size()-1;
        int num2 = 0;
         prev = 1;
        while(j>=1){
            int k = s2[j]-'0';
            num2 = num2+k*prev;
            prev = prev*10;
            j--;
        }
        int val2 = grid[num2-1][col];
            return num+val2;
        
            
        }
        else if(!flag1 && flag2){
        int j = s2.size()-1;
        int num = 0;
        int prev = 1;
        while(j>=0){
            int k = s2[j]-'0';
            num = num+k*prev;
            prev = prev*10;
            j--;
        }
         char ch1 = s1[0];
        int col = ch1-'A';
         j = s1.size()-1;
        int num2 = 0;
         prev = 1;
        while(j>=1){
            int k = s1[j]-'0';
            num2 = num2+k*prev;
            prev = prev*10;
            j--;
        }
        int val2 = grid[num2-1][col];
            return num+val2;
        
            
        }
        else{
         char ch1 = s2[0];
        int col = ch1-'A';
         j = s2.size()-1;
        int num2 = 0;
        int  prev = 1;
        while(j>=1){
            int k = s2[j]-'0';
            num2 = num2+k*prev;
            prev = prev*10;
            j--;
        }
        int val2 = grid[num2-1][col];
          ch1 = s1[0];
         col = ch1-'A';
         j = s1.size()-1;
        int num1 = 0;
         prev = 1;
        while(j>=1){
            int k = s1[j]-'0';
            num1 = num1+k*prev;
            prev = prev*10;
            j--;
        }
        int val1 = grid[num1-1][col];
            return val1+val2;
        



            
        }
        
        
    }
};

/**
 * Your Spreadsheet object will be instantiated and called as such:
 * Spreadsheet* obj = new Spreadsheet(rows);
 * obj->setCell(cell,value);
 * obj->resetCell(cell);
 * int param_3 = obj->getValue(formula);
 */
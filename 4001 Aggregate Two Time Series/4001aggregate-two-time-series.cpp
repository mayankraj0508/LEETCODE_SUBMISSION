class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& babua, vector<vector<int>>& manua) {
        
   
         int chotu = babua.size();
        int motu = manua.size();

        int laika = 0, laiki = 0;

        vector<vector<int>> jugaad;

        while (laika < chotu || laiki < motu) {

            int samay;

            if (laiki == motu || (laika < chotu && babua[laika][0] < manua[laiki][0]))
                samay = babua[laika][0];
            else if (laika == chotu || manua[laiki][0] < babua[laika][0])
                samay = manua[laiki][0];
            else
                samay = babua[laika][0];

            int paisa = 0, dhan = 0;

            if (laika < chotu) paisa = babua[laika][1];
            if (laiki < motu) dhan = manua[laiki][1];

            jugaad.push_back({samay, paisa + dhan});

            if (laika < chotu && babua[laika][0] == samay) laika++;
            if (laiki < motu && manua[laiki][0] == samay) laiki++;
        }
       return jugaad;


        
    }
};
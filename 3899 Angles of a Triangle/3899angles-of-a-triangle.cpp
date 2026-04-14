class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {
        
        double a = sides[0];
        double b = sides[1];
        double c = sides[2];
        
        // 1. Triangle valid hai ya nahi
        if(a + b <= c || b + c <= a || a + c <= b){
            return {};
        }
        
        // 2. Cosine rule apply karo
        double A = acos((b*b + c*c - a*a) / (2*b*c));
        double B = acos((a*a + c*c - b*b) / (2*a*c));
        double C = acos((a*a + b*b - c*c) / (2*a*b));
        
        // 3. Radians → Degrees
        double rad_to_deg = 180.0 / 3.141592653589793;
        A *= rad_to_deg;
        B *= rad_to_deg;
        C *= rad_to_deg;
        
        vector<double> ans = {A, B, C};
        
      
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};
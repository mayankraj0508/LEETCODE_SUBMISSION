class Solution {
public:
    int numRescueBoats(vector<int>& people, int limits) {
        int n = people.size();
        sort(people.begin(),people.end());
        int i= 0;
        int j = n-1;
        int ans = 0;
        while(i<=j){
            if(people[i]+people[j]<=limits){
               ans++;
               i++;
               j--;
            }
            else if(people[i]+people[j]>limits){
                j--;
                ans++;
            }
        }
        return ans;
 

        
    }
};
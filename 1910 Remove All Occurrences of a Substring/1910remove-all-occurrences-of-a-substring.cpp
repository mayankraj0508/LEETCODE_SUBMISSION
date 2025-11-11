// class Solution {
// public: 
//     vector<int>build(string &part){
//        vector<int>lps(part.size(),0);
//        int pre= 0;
//        int suf = 1;
//        while(suf<lps.size()){
//         if(part[pre]==part[suf]){
//             lps[suf] = pre+1;
//             pre++;
//             suf++;
//         }
//         else {
//             if(pre==0){
//                 lps[suf] =0;
//                 suf++;
//             }
//             else{
//                 pre = lps[pre-1];

//             }
//         }
//        }
//        return lps;
//     }
//     int kmp(vector<int>&lps,string &s,string &t){
//         int i =0;
//         int j =0;
//         while(i<s.size()){
//             if(s[i]==t[j]){
//                 i++;
//                 j++;
//                if(j==t.size()){
//                 return i-j;
//                }
//             }
//             else{
//                 if(j==0){
//                     i++;
//                 }
//                 else{
//                     j = lps[j-1];
//                 }
//             }
//         }
//         return -1;


//     }
//     string removeOccurrences(string s, string part) {
//         int m = part.size();
//         vector<int>lps = build(part);
//         int partition = kmp(lps,s,part);
//         if(partition==-1){
//             return s;
//         }
//         while(partition!=-1){
//                partition  = kmp(lps,s,part);
//               if(partition ==-1){
//                 return s;
//               }
//             string left = s.substr(0,partition);
//             string right = s.substr(partition+m,s.size());
//             s = left+right;
//         }
//         return s;
//     }
// };
class Solution{
    public:
    string removeOccurrences(string s, string part){
        string ans = "";
        int i =0;
        int m = part.size();
        while(i<s.size()){
            ans.push_back(s[i]);
            if(ans.size()>=m&&ans.substr(ans.size()-m)==part){
                ans.resize(ans.size()-m);
            }
            i++;
        }
        return ans;
    }
   


};
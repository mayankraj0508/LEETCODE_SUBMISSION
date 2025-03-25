class Solution {
public:
int rev(int n){
    int rev = 0;
    while(n>0){
        rev = rev*10;
        rev = rev+n%10;
        n = n/10;
    }
    return rev;
}
/*int fact(int n){
    int y = 1;
    if(n==0||n==1){
        return 1;
    }
    y = n*fact(n-1);
    return y;
    
 }
 //combination se v solve kar skte h
int combinate(int a,int b){
    int p =fact(a)/fact(b)*fact(a-b);
    return p;

}*/
    int countNicePairs(vector<int>& nums) {
        //nums[i]-rev[nums[i]] = nums[j]-rev[nums[j]];
        long long count =0;
        unordered_map<int,int>m;
        for(int i=0; i<nums.size();i++){
            nums[i] = nums[i]-rev(nums[i]);
           
        }
         for(int i=0; i<nums.size();i++){
            if(m.find(nums[i])!=m.end()){
                count  =  count%1000000007;
                count = count + m[nums[i]];
            }
            m[nums[i]]++;
           
        }       
        return count%1000000007;   
    
    }
};
class Solution {
public:
    long long  ans= 0;
void merge(vector<int>&a,vector<int>&b,vector<int>&res){
    int i = 0;
    int j = 0;
    int k = 0;
    while(i<a.size()&&j<b.size()){
        if(a[i]<b[j]){
            res[k] = a[i];
            i++;
            k++;
        }
        else{
            res[k] = b[j];
            j++;
            k++;
        }
    }
    while(j<b.size()){
        res[k] = b[j];
        j++;
        k++;
    }
     while(i<a.size()){
        res[k] = a[i];
        i++;
        k++;
    }


}
long long inversion(vector<int >&a,vector<int>&b){
    int i =0;
    int j = 0;
    int count = 0;
    while(i<a.size()&&j<b.size()){
        if((long long)a[i]>(long long)2*b[j]){
            count = count +a.size()-i;
            j++;
        }
        else{
            i++;
        }
    }
    return count;
     
}
void mergesort(vector<int>&v){
    int n = v.size();
    if(n==1){
        return ;
    }
    int n1 = n/2;
    int n2 = n-n1;
    vector<int>a(n1);
    vector<int>b(n2);
    for(int i =0; i<n1; i++){
        a[i]  = v[i];
    }
    for(int j = 0; j<n2; j++){
        b[j] = v[j+n1];
    }
    mergesort(a);
    mergesort(b);
    ans = ans+inversion(a,b);
    merge(a,b,v);
    a.clear();
    b.clear();

}
    int reversePairs(vector<int>& nums) {
        mergesort(nums);
        return ans;
        
    }
};
class RangeFreqQuery {
public:
    vector<unordered_map<int,int>>st;
    int n;
    vector<int>nums;
  unordered_map<int,int> addMaps(unordered_map<int,int>& m1,
                               unordered_map<int,int>& m2)
{
    unordered_map<int,int> m;

    // Traverse first map
    for(auto x : m1){
        if(m2.find(x.first) != m2.end()){
            m[x.first] = x.second + m2[x.first];
        }
        else{
            m[x.first] = x.second;
        }
    }

    // Traverse second map for remaining keys
    for(auto x : m2){
        if(m1.find(x.first) == m1.end()){
            m[x.first] = x.second;
        }
    }

    return m;
}
   void buildTree(int i,int lo,int hi){
        if(lo==hi){
            st[i][nums[lo]] = 1;
            return ;
        }
        int mid = lo+(hi-lo)/2;
        buildTree(2*i+1,lo,mid);
        buildTree(2*i+2,mid+1,hi);
        st[i] = addMaps(st[2*i+1],st[2*i+2]);
    }
    int ans(int i,int lo,int hi,int l,int r,int val){
        int mid = lo+(hi-lo)/2;
        if(hi<l||lo>r){
            return 0;
        }
        else if(lo>=l&&r>=hi){
            if(st[i].find(val)!=st[i].end()){
                return st[i][val];
            }
            else{
                return 0;
            }
            
        }
        else{
            return ans(2*i+1,lo,mid,l,r,val)+ans(2*i+2,mid+1,hi,l,r,val);
        }

    }
    RangeFreqQuery(vector<int>& arr) {
        nums = arr;
        n = arr.size();  
        st.resize(4*n);
        buildTree(0,0,n-1);
    }
    
    int query(int left, int right, int value) {
        return ans(0,0,nums.size()-1,left,right,value);
        
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */
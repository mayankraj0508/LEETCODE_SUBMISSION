class NumArray {
public:
    vector<int>st;
    vector<int>num;
     void buildTree(vector<int>&num,int i,int lo,int hi){
          int mid = lo+(hi-lo)/2;
          if(lo==hi){
            st[i] = num[lo];
            return ;
          }
          buildTree(num,2*i+1,lo,mid);
          buildTree(num,2*i+2,mid+1,hi);
          st[i] = st[2*i+1]+st[2*i+2];
     }
    NumArray(vector<int>& nums) {
        st.resize(4*nums.size());
        num  = nums;
        buildTree(num,0,0,num.size()-1);
    }
    
     int  findsum(int  i,int l,int r,int lo,int hi){
        int mid = lo+(hi-lo)/2;

        if(l>hi||r<lo){
            return 0;
        }
        else if(lo>=l&&hi<=r){
            return st[i];
        }
        else{
           return  findsum(2*i+1,l,r,lo,mid)+findsum(2*i+2,l,r,mid+1,hi);
        }
     }
    void updation(int i,int index,int val,int lo,int hi ){
        int mid= lo+(hi-lo)/2;
        if(lo==hi&&lo==index){
            st[i] = val;
            return ;
        }
        if(index<=mid){
            updation(2*i+1,index,val,lo,mid);
        }
        else{
            updation(2*i+2,index,val,mid+1,hi);
        }
        st[i] = st[2*i+1]+st[2*i+2];
    }
    void update(int index, int val) {
        num[index] = val;
        updation(0,index,val,0,num.size()-1);
        
        
    }
    int sumRange(int left, int right) {
        return findsum(0,left,right,0,num.size()-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
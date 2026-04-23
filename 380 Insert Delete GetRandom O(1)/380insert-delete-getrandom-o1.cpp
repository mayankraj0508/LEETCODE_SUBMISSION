class RandomizedSet {
public:
    vector<int>nums;
    unordered_map<int,int>m;
    int idx ;
     RandomizedSet() {
        idx = 0;
        
    }
    
    bool insert(int val) {
       if(m.find(val)!=m.end()){
           return false;
       }
       else{
        nums.push_back(val);
        m[val] = nums.size()-1;
        return true;
       }
        
    }
    
    bool remove(int val) {
       if(m.find(val)==m.end()){
        return false;
       }
       else{
        int idx = m[val];
        nums[idx] = nums[nums.size()-1];
        m[nums[nums.size()-1]] = idx;
        m.erase(val);
        nums.pop_back();
        return true;
        }
    }
    
    int getRandom() {
      int idx = rand()%nums.size();
    return nums[idx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
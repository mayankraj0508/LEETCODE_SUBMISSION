class MyCalendar {
public:
    #define pp pair<int,int>
    vector<pp>v;
    MyCalendar() {
        
    }
    
    bool book(int startime, int endtime) {
        if(v.size()==0){
            v.push_back({startime,endtime});
            return true;
        }
        else{
            for(int i =0; i<v.size(); i++){
                if(v[i].second>startime&&v[i].first<endtime){
                    return false;
                }

            }
            v.push_back({startime,endtime});
            return true;
        }
        
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(startTime,endTime);
 */
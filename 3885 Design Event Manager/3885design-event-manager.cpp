class EventManager {
public:
    #define pp pair<int,int>
    priority_queue<pp>pq;
    unordered_map<int,int>m;
    EventManager(vector<vector<int>>& events) {
        int n = events.size();
        for(int i = 0; i<n; i++){
            pq.push({events[i][1],-events[i][0]});
            m[events[i][0]] = events[i][1];
        }
    }
    
    void updatePriority(int eventId, int newPriority) {
        m[eventId] = newPriority;
        pq.push({newPriority,-eventId});
    }
    
    int pollHighest() {
        if(m.size()==0){
            return -1;
        }
        if(pq.size()){
           
         while(!pq.empty()){
    int id = -pq.top().second;
    int pr = pq.top().first;

    if(m.find(id) != m.end() && m[id] == pr){
        break;
    }
    pq.pop();
}
            auto x = pq.top();
            pq.pop();
            
            int y = -x.second;
            
            m.erase(y);
            
            return y;
        }
        return -1;
        
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */
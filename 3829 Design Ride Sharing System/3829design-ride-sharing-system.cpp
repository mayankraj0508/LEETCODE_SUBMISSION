class RideSharingSystem {
public:
    queue<int>qr;
    queue<int>qd;
    unordered_set<int>rider;
    RideSharingSystem() {
        
    }
    
    void addRider(int riderId) {
        qr.push(riderId);
        rider.insert(riderId);
    }
    
    void addDriver(int driverId) {
        qd.push(driverId);   
    }
    vector<int> matchDriverWithRider() {
        if(qr.size()==0 || qd.size()==0){
            return {-1,-1};
        }
        else{
            int driver = qd.front();
           int ride = qr.front();
           // qr.pop();
          
            if(rider.find(ride)==rider.end()){
                while(qr.size()>0 && rider.find(qr.front())==rider.end()){
                    qr.pop();
                    
                }
                  if(qr.size()==0){
                    return {-1,-1};
                }
                ride = qr.front();
                qr.pop();
                
                
                
            }
            qd.pop();
            rider.erase(ride);
            return {driver,ride};
        }
    }
    
    void cancelRider(int riderId) {
        if(rider.find(riderId)!=rider.end()){
            rider.erase(riderId);
        }
    }
};

/**
 * Your RideSharingSystem object will be instantiated and called as such:
 * RideSharingSystem* obj = new RideSharingSystem();
 * obj->addRider(riderId);
 * obj->addDriver(driverId);
 * vector<int> param_3 = obj->matchDriverWithRider();
 * obj->cancelRider(riderId);
 */
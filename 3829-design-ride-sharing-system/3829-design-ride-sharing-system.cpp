class RideSharingSystem {
public:
    unordered_set<int> riders;
    queue<int> ridersList;
    queue<int> driversList;

    RideSharingSystem() {
        
    }
    
    void addRider(int riderId) {
        riders.insert(riderId);
        ridersList.push(riderId);
    }
    
    void addDriver(int driverId) {
        driversList.push(driverId);
    }
    
    vector<int> matchDriverWithRider() {
        while(!ridersList.empty() && !riders.count(ridersList.front())) {
            ridersList.pop();
        }

        if(ridersList.empty() || driversList.empty())
            return {-1, -1};

        int r = ridersList.front();
        int d = driversList.front();

        ridersList.pop();
        driversList.pop();
        riders.erase(r);  

        return {d, r};
    }
    
    void cancelRider(int riderId) {
        if(riders.count(riderId)){
            riders.erase(riderId);
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
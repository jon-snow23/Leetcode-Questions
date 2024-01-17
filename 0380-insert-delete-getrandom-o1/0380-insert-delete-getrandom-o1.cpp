class RandomizedSet {
public:
    RandomizedSet() {
        
    }
    vector<int>v;
    map<int,int>mp;
    
    bool insert(int val) {
        if(mp.find(val)!=mp.end())return false;
        else{
            mp[val]++;
            v.push_back(val);
            return true;
        }
        
    }
    
    bool remove(int val) {
        if(mp.find(val)==mp.end())return false;
        else{
            mp.erase(val);
            auto it=find(v.begin(),v.end(),val);
            v.erase(it);
            return true;
        }
        
    }
    
    int getRandom() {
        int randomNo = rand()%v.size();
        return v[randomNo];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */
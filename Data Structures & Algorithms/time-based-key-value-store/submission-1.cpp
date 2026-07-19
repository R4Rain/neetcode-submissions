class TimeMap {
public:
    unordered_map<string, set<pair<int, string>>> mp;

    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        mp[key].insert({timestamp, value});
    }
    
    string get(string key, int timestamp) {
        auto it = mp[key].lower_bound({timestamp + 1, ""});
        if (mp[key].empty()) return "";

        if (it != mp[key].begin()) {
            --it;
        }
        if (it->first <= timestamp) {
            return it->second;
        } else {
            return "";
        }  
    }
};

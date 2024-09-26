class MyCalendar {
public:
    vector<pair<int,int>>v;
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        int n = v.size();
        for(int i=0;i<n;i++){
            int vs = v[i].first;
            int ve = v[i].second;

            if(start<=vs && end> vs) return false;
            else if(start >=vs && start < ve) return false;
        }
        v.push_back({start,end});
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
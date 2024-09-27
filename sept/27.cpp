class MyCalendarTwo {
private:
    vector<pair<int,int>>sb, db;
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        //first check this in double
        for(int i=0;i<db.size();i++){
            auto temp = db[i];
            int vs = temp.first;
            int ve = temp.second;
            if(max(start,vs) < min(ve, end)){
                return false;
            }
        }

        for(int i=0;i<sb.size();i++){
            auto temp = sb[i];
            int vs = temp.first;
            int ve = temp.second;
            if(max(start, vs) < min(ve, end)){
                db.push_back({max(start,vs), min(ve,end)});
            }
        }

        sb.push_back({start, end});
        return true;
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
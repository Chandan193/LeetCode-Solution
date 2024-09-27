class MyCalendarTwo {
public:
    map<int, int> events;

    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
    events[start]++;
    events[end]--;

    int ongoing = 0;
    for (auto it = events.begin(); it != events.end(); ++it) {
        ongoing += it->second;
        if (ongoing >= 3) {
            events[start]--;
            events[end]++;
            return false;
            }
        }
        return true; 
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
class NumberContainers {
private:
    unordered_map<int, int> m;
    unordered_map<int, set<int>> n;

public:
    NumberContainers() {}
    
    void change(int i, int v) {
        if (m.find(i) != m.end()) {
            int o = m[i];
            n[o].erase(i);
            if (n[o].empty()) {
                n.erase(o);
            }
        }
        m[i] = v;
        n[v].insert(i);
    }
    
    int find(int v) {
        if (n.find(v) != n.end() && !n[v].empty()) {
            return *n[v].begin();
        }
        return -1;
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
// design and implement a data structure for least recently used (LRU) cache, it should support the following
// operations : get and put

class LRUCache {
    int cap;
    std::list<std::pair<int, int> > l;
    std::unordered_map<int, std::list<std::pair<int, int>>::iterator> m;
public:
    LRUCache(int capacity) {
        cap = capacity;
    }

    int get(int key) {
        auto it = m.find(key);
        if (it == m.end()) {
            return -1;
        }
        l.splice(l.begin(), l, it->second);
        return it->second->second;
    }

    void put(int key, int value) {
        auto it = m.find(key);
        if (it != m.end()) {
            l.erase(it->second);
        }
        l.push_front(std::make_pair(key, value));
        m[key] = l.begin();
        if (m.size() > cap) {
            int k = l.rbegin()->first;
            l.pop_back();
            m.erase(k);
        }
    }
};

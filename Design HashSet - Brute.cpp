class MyHashSet {
public:
    vector<int> mySet;
    MyHashSet() {
      mySet.resize(1e7+1);
    }
    
    void add(int key) {
        mySet[key] = 1;
    }
    
    void remove(int key) {
        mySet[key] = 0;
    }
    
    bool contains(int key) {
        return mySet[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
class Node {
public:
    int key;
    Node* next;
    Node* prev;
    
    Node(int _key) {
        key = _key;
        next = NULL;
        prev = NULL;
    }
};

class LRUCache {
public:
    Node* head = NULL;
    Node* tail = NULL;
    map<int, pair<Node*, int>> mp;
    int cap;
    int curr;
    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(0);
        tail = new Node(0);
        head->next = tail;
        tail->prev = head;
        curr = 0;
    }
    
    void remove(Node* node) {
        // Remove Node from the list
        Node* prev = node->prev;
        Node* next = node->next;
        prev->next = next;
        next->prev = prev;
        int key = node->key;
        mp[key] = {NULL, -1};
    }
    
    void insert(int key, int val) {
        Node* temp = new Node(key);
        temp->next = head->next;
        (head->next)->prev = temp;
        head->next = temp;
        temp->prev = head;
        mp[key] = make_pair(temp, val);
    }
    
    void set(Node* node, int key, int val) {
        // Remove Node from the list
        remove(node);
        // Create a new node in the beginning
        insert(key, val);
    }
    
    int get(int key) {
        if (mp.count(key) == 0 || mp[key].second == -1) return -1;
        set(mp[key].first, key, mp[key].second);
        return mp[key].second;
    }
    
    void put(int key, int value) {
        bool ok = false;
        if (mp.count(key) == 0) ok = true;
        if (mp.count(key) > 0 && mp[key].second != -1) set(mp[key].first, key, value);
        else if (curr >= cap) set(tail->prev, key, value);
        else insert(key, value);
        curr += (ok ? 1 : 0);
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
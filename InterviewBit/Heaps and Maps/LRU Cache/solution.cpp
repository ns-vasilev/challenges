/*

LRU Cache

Design and implement a data structure for LRU (Least Recently Used) cache. It should support the following operations: get and set.

- get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
- set(key, value) - Set or insert the value if the key is not already present. When the cache reaches its capacity, it should invalidate the least recently used item before inserting the new item.

The LRU Cache will be initialized with an integer corresponding to its capacity. Capacity indicates the maximum number of unique keys it can hold at a time.

Definition of “least recently used” : An access to an item is defined as a get or a set operation of the item. “Least recently used” item is the one with the oldest access time.

NOTE: If you are using any global variables, make sure to clear them in the constructor.

Example:

Input: 
         capacity = 2
         set(1, 10)
         set(5, 12)
         get(5)        returns 12
         get(1)        returns 10
         get(10)       returns -1
         set(6, 14)    this pushes out key = 5 as LRU is full. 
         get(5)        returns -1 
*/

struct node {
    int key;
    int value;
    node *next;
    node *prev;
    
    node(int key, int value) {
        this->key = key;
        this->value = value;
        next = nullptr;
        prev = nullptr;
    }
};

int cap;

std::unordered_map<int, node*> m;

node *head;
node *tail;

void remove(node* n) {
    m.erase(n->key);
    
    n->prev->next = n->next;
    n->next->prev = n->prev;
}

void insert(node *n) {
    n->next = head->next;
    head->next->prev = n;
    head->next = n;
    n->prev = head;
    m[n->key] = n;
}

LRUCache::LRUCache(int capacity) {
    cap = capacity;
    head = new node(0, 0);
    tail = new node(0, 0);
    head->next = tail;
    tail->prev = head;
    m.clear();
}

int LRUCache::get(int key) {
    if (m.count(key) == 0) { return -1; }
    
    node *n = m[key];
    
    remove(n);
    insert(n);
    
    return m[key]->value;
}

void LRUCache::set(int key, int value) {
    if (m.count(key) > 0) {
        remove(m[key]);
    }
    
    if (m.size() == cap) {
        remove(tail->prev);
    }
    
    insert(new node(key, value));
}

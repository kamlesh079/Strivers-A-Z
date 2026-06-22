// https://leetcode.com/problems/lru-cache

class LRUCache {
public:
    // ##### Node Structure #####
    class Node {
    public:
        int key;
        int value;

        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            value = v;
            prev = NULL;
            next = NULL;
        }
    };
    // ##### Global Variables and data structures #####
    unordered_map<int, Node*> mp;
    Node* head;
    Node* tail;
    int cap;

    // ## LeetCode's ctor ##
    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(-1, -1); // dummy head
        tail = new Node(-1, -1); // dummy tail

        head->next = tail;
        tail->prev = head;
    }

    // Helper fun 1 (Remove Node)
    void remove(Node* node) {
        Node* p = node->prev;
        Node* n = node->next;

        p->next = n;
        n->prev = p;
    }

    // Helper fun 2 (Insert at tail)
    void insertAtEnd(Node* node) {

        Node* preNode = tail->prev;

        preNode->next = node;
        node->prev = preNode;

        node->next = tail;
        tail->prev = node;
    }

    // ## LeetCode's Function ##
    int get(int key) {
        if (mp.find(key) == mp.end())
            return -1;

        Node* node = mp[key];

        // latest used
        remove(node);
        insertAtEnd(node);

        return node -> value;
    }

    // ## LeetCode's Function ##
    void put(int key, int value) {
        // If it is present already
        if (mp.find(key) != mp.end()) {

            Node* node = mp[key];

            node->value = value;

            remove(node);
            insertAtEnd(node);

            return;
        }

        Node* node = new Node(key, value);
        mp[key] = node;
        insertAtEnd(node);

        if (mp.size() > cap) {

            Node* lru = head->next;
            remove(lru);
            mp.erase(lru->key);

            delete lru;
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
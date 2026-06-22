// https://leetcode.com/problems/lfu-cache/

class LFUCache {
public:
    // ##### Node Structure #####
    class Node {
    public:
        int key;
        int value;
        int freq;

        Node* prev;
        Node* next;

        Node(int k, int v) {
            key = k;
            value = v;
            freq = 1;       // New node starts with frequency 1

            prev = nullptr;
            next = nullptr;
        }
    };

    // Doubly linked list for nodes having same frequency
    class List {
    public:
        int size;

        Node* head;
        Node* tail;

        List() {
            head = new Node(-1, -1);
            tail = new Node(-1, -1);

            head->next = tail;
            tail->prev = head;

            size = 0;
        }

        // Insert node right after head (most recently used)
        void addFront(Node* node) {
            node->next = head->next;
            node->prev = head;

            head->next->prev = node;
            head->next = node;

            size++;
        }

        // Remove node from list
        void remove(Node* node) {
            Node* prevNode = node->prev;
            Node* nextNode = node->next;

            prevNode->next = nextNode;
            nextNode->prev = prevNode;

            size--;
        }

        // Remove least recently used node of this frequency
        Node* removeLast() {
            if (size == 0) return nullptr;

            Node* node = tail->prev;
            remove(node);

            return node;
        }
    };

    // key -> node
    unordered_map<int, Node*> keyTable;

    // freq -> DLL of nodes with that frequency
    unordered_map<int, List*> freqTable;

    int capacity;
    int currSize;

    // Minimum frequency currently present in cache
    int minFreq;

    LFUCache(int capacity) {
        this->capacity = capacity;

        currSize = 0;
        minFreq = 0;
    }

    // Move node from freq f to freq f+1
    void updateFrequency(Node* node) {

        int currFreq = node->freq;

        // Remove node from old frequency list
        freqTable[currFreq]->remove(node);

        /*
            If current frequency was the minimum frequency
            and after removing node the list becomes empty,
            increase minFreq.
        */
        if (currFreq == minFreq &&
            freqTable[currFreq]->size == 0) {
            minFreq++;
        }

        // Increase node frequency
        node->freq++;

        // Create new frequency list if absent
        if (freqTable.find(node->freq) == freqTable.end()) {
            freqTable[node->freq] = new List();
        }

        // Insert into new frequency list
        freqTable[node->freq]->addFront(node);
    }

    int get(int key) {

        // Key not present
        if (keyTable.find(key) == keyTable.end()) {
            return -1;
        }

        Node* node = keyTable[key];

        // Access increases frequency
        updateFrequency(node);

        return node->value;
    }

    void put(int key, int value) {

        if (capacity == 0) return;

        // Key already exists
        if (keyTable.find(key) != keyTable.end()) {

            Node* node = keyTable[key];

            node->value = value;

            // Updating existing key also counts as access
            updateFrequency(node);

            return;
        }

        // Cache full -> remove LFU node
        if (currSize == capacity) {

            // Least recently used node from minimum frequency list
            Node* node = freqTable[minFreq]->removeLast();

            keyTable.erase(node->key);

            delete node;

            currSize--;
        }

        // Create new node
        Node* node = new Node(key, value);

        // New node always has frequency 1
        minFreq = 1;

        if (freqTable.find(1) == freqTable.end()) {
            freqTable[1] = new List();
        }

        freqTable[1]->addFront(node);

        keyTable[key] = node;

        currSize++;
    }
};
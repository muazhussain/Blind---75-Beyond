// Problem link: https://leetcode.com/problems/lru-cache/
// Time: Get -> O(1), Put -> ~O(1)
// Space: O(capacity)

class LRUCache {
private:
	int capacity;

	struct Node {
		int key;
		int value;
		Node* prev;
		Node* next;
		Node(int key, int value) {
			this->key = key;
			this->value = value;
			prev = nullptr;
			next = nullptr;
		}
	};

	Node* head;
	Node* tail;
	
	unordered_map<int, Node*> lookup;

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
    }

    ~LRUCache() {
        Node* current = head;
        while (current) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    void deleteNode(Node* node) {
    	node->prev->next = node->next;
    	node->next->prev = node->prev;
    }

    void insertAfterHead(Node* node) {
    	node->next = head->next;
    	head->next->prev = node;
    	head->next = node;
    	node->prev = head;
    }
    
    int get(int key) {
        if(lookup.find(key) == lookup.end()) {
        	return -1;
        }
        Node* current = lookup[key];
        deleteNode(current);
        insertAfterHead(current);
        return current->value;
    }
    
    void put(int key, int value) {
        if(lookup.find(key) == lookup.end()) {
        	Node* newNode = new Node(key, value);
        	if(lookup.size() == capacity) {
        		Node* toBeDeleted = tail->prev;
        		lookup.erase(toBeDeleted->key);
        		deleteNode(toBeDeleted);
        		delete toBeDeleted;
        	}
        	insertAfterHead(newNode);
        	lookup[key] = newNode;
        } else {
        	Node* current = lookup[key];
        	current->value = value;
        	deleteNode(current);
        	insertAfterHead(current);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
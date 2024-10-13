// Problem link: https://leetcode.com/problems/lfu-cache/
// Time: O(1)
// Space: O(1)

class LFUCache {
private:
	struct Node {
		int key;
		int value;
		int count;
		Node* prev;
		Node* next;
		Node(int key, int value) {
			this->key = key;
			this->value = value;
			this->count = 1;
			prev = nullptr;
			next = nullptr;
		}
	};

	struct List {
		int size;
		Node* head;
		Node* tail;
		List() {
			size = 0;
			head = new Node(0, 0);
			tail = new Node(0, 0);
			head->next = tail;
			tail->prev = head;
		}

		void addFront(Node* newNode) {
			newNode->next = head->next;
			head->next->prev = newNode;
			head->next = newNode;
			newNode->prev = head;
			size++;
		}

		void removeNode(Node* delNode) {
			delNode->prev->next = delNode->next;
			delNode->next->prev = delNode->prev;
			size--;
		}
	};

	unordered_map<int, Node*> keyNode;
	unordered_map<int, List*> freqListMap;

	int minFreq;
	int curSize;
	int capacity;

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
        curSize = 0;
    }

    void updateFreqListMap(Node* node) {
    	keyNode.erase(node->key);
    	freqListMap[node->count]->removeNode(node);
    	if(node->count == minFreq && freqListMap[node->count]->size == 0) {
    		minFreq++;
    	}
    	List* nextHigherFreqList = new List();
    	if(freqListMap.find(node->count + 1) != freqListMap.end()) {
    		nextHigherFreqList = freqListMap[node->count + 1];
    	}
    	node->count += 1;
    	nextHigherFreqList->addFront(node);
    	freqListMap[node->count] = nextHigherFreqList;
    	keyNode[node->key] = node;
    }
    
    int get(int key) {
        if(keyNode.find(key) != keyNode.end()) {
        	Node* node = keyNode[key];
        	updateFreqListMap(node);
        	return node->value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(capacity == 0) {
        	return;
        }
        if(keyNode.find(key) != keyNode.end()) {
        	Node* node = keyNode[key];
        	node->value = value;
        	updateFreqListMap(node);
        } else {
        	if(curSize == capacity) {
        		List* list = freqListMap[minFreq];
        		keyNode.erase(list->tail->prev->key);
        		freqListMap[minFreq]->removeNode(list->tail->prev);
        		curSize--;
        	}
        	curSize++;
        	minFreq = 1;
        	List* listFreq = new List();
        	if(freqListMap.find(minFreq) != freqListMap.end()) {
        		listFreq = freqListMap[minFreq];
        	}
        	Node* node = new Node(key, value);
        	listFreq->addFront(node);
        	keyNode[key] = node;
        	freqListMap[minFreq] = listFreq;
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
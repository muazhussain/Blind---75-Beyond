// Problem link: https://leetcode.com/problems/implement-trie-prefix-tree/
// Time: O(len)
// Space: O(len^26)

class Trie {
private:
	bool endmark;
	vector<Trie*> next;

public:
    Trie() {
        endmark = false;
        next.resize(26, NULL);
    }
    
    void insert(string word) {
        Trie* current = this;
        for(char ch : word) {
        	if(current->next[ch - 'a'] == NULL) {
        		current->next[ch - 'a'] = new Trie();
        	}
        	current = current->next[ch - 'a'];
        }
        current->endmark = true;
    }
    
    bool search(string word) {
    	Trie* current = this;
    	for(char ch : word) {
    		if(current->next[ch - 'a'] == NULL) {
    			return false;
    		}
    		current = current->next[ch - 'a'];
    	} 
    	return current->endmark;
    }
    
    bool startsWith(string prefix) {
        Trie* current = this;
    	for(char ch : prefix) {
    		if(current->next[ch - 'a'] == NULL) {
    			return false;
    		}
    		current = current->next[ch - 'a'];
    	} 
    	return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
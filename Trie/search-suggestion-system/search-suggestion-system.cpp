// Problem link: https://leetcode.com/problems/search-suggestions-system/
// Time: 
// Space:

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
    
    vector<string> search(string prefix) {
    	Trie* current = this; 
    	vector<string> products; 
    	for(char ch : prefix) {
    		if(current->next[ch - 'a'] == NULL) {
    			return products;
    		}
    		current = current->next[ch - 'a'];
    	} 
    	dfs(current, prefix, products);
    	return products;
    }
    
    void dfs(Trie* t, string path, vector<string>& products) {
    	if(products.size() >= 3) {
    		return;
    	}
    	if(t->endmark == true) {
    		products.push_back(path);
    	}
    	for(int i = 0; i < 26; i++) {
    		if(t->next[i] != NULL) {
    			dfs(t->next[i], path + char('a' + i), products);
    		}
    	}	
    }
    
};

class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie t;
        for(string product : products) {
        	t.insert(product);
        }
        vector<vector<string>> res;
        string prefix = "";
        for(char ch : searchWord) {
        	prefix += ch;
        	res.push_back(t.search(prefix));
        }
        return res;
    }
};
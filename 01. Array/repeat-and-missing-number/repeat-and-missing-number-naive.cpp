// Problem link: https://www.geeksforgeeks.org/problems/find-missing-and-repeating2512/1
// Time: O(n)
// Space: O(n)

class Solution {
  public:
    vector<int> findTwoElement(vector<int> arr) {
        map<int, int> count;
    	for(int e : arr) {
    		count[e]++;
    	}
    	int repeat = 0;
    	for(auto p : count) {
    		if(p.second > 1) {
    			repeat = p.first;
    			break;
    		}
    	}
    	int missing = 0;
    	for(int i = 1; i <= arr.size(); i++) {
    		if(count.find(i) == count.end()) {
    			missing = i;
    			break;
    		}
    	}
    	return {repeat, missing};
    }
};
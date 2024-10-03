// Problem link: https://leetcode.com/problems/maximum-matching-of-players-with-trainers/
// Time: O(nlogn + mlogm)
// Space: O(1)

class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());
        int i = 0, j = 0;
        while(i < players.size() && j < trainers.size()) {
        	if(players[i] <= trainers[j]) {
        		i++;
        	}
        	j++;
        }
        return i;
    }
};
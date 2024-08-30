// Problem link:
// Time: O(nlogn)
// Space: O(1)

class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [] (const auto box1, const auto box2) {
        	return box1[1] > box2[1];
        });

        int res = 0;
        for(auto box : boxTypes) {
        	int take = min(truckSize, box[0]);
        	res += (take * box[1]);
        	truckSize -= take;
        	if(truckSize == 0) {
        		break;
        	}
        }
        return res;
    }
};
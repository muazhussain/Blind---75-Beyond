// Problem link: https://www.naukri.com/code360/problems/partition-a-set-into-two-subsets-such-that-the-difference-of-subset-sums-is-minimum_842494
// Time: O(n * k)
// Space: O(k)

int minSubsetSumDifference(vector<int>& nums, int n) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    vector<bool> prev(sum + 1, 0);
    prev[0] = true;
    prev[nums[0]] = true;
    for(int index = 1; index < n; index++) {
        vector<bool> curr(sum + 1, 0);
        curr[0] = true;
        for(int target = 1; target <= sum; target++) {
            bool notTake = prev[target];
            bool take = false;
            if(target >= nums[index]) {
                take = prev[target - nums[index]];
            }
            curr[target] = take | notTake;
        }
        prev = curr;
    }
    int res = sum;
    for(int i = 0; i <= sum / 2; i++) {
        if(prev[i]) {
			res = min(res, abs((sum - i) - i));
		}
    }
    return res;
}
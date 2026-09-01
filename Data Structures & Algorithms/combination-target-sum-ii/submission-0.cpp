class Solution {
public:
    void solve(vector<int>& nums, int target,
               vector<int>& ds, vector<vector<int>>& ans,
               int idx) {

        if (target == 0) {
            ans.push_back(ds);
            return;
        }

        if (idx == nums.size())
            return;

        // Take nums[idx]
        if (nums[idx] <= target) {
            ds.push_back(nums[idx]);

            solve(nums, target - nums[idx], ds, ans, idx + 1);

            ds.pop_back();
        }

        // Skip all duplicates before not taking
        int next = idx + 1;

        while (next < nums.size() &&
               nums[next] == nums[idx]) {
            next++;
        }

        solve(nums, target, ds, ans, next);
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates,
                                        int target) {

        sort(candidates.begin(), candidates.end());

        vector<vector<int>> ans;
        vector<int> ds;

        solve(candidates, target, ds, ans, 0);

        return ans;
    }
};

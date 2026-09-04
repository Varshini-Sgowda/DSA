class Solution {
public:
    void backtrack(vector<int>& nums, vector<bool>& used,
                   vector<int>& current, vector<vector<int>>& result) {

        // If current permutation has all elements
        if (current.size() == nums.size()) {
            result.push_back(current);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {

            // Skip if this element is already used
            if (used[i]) {
                continue;
            }

            used[i] = true;
            current.push_back(nums[i]);

            backtrack(nums, used, current, result);

            // Backtrack
            current.pop_back();
            used[i] = false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        vector<bool> used(nums.size(), false);

        backtrack(nums, used, current, result);

        return result;
    }
};
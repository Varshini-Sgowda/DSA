class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {

        // Sort intervals by starting time
        sort(intervals.begin(), intervals.end());

        vector<vector<int>> result;

        for (auto& interval : intervals) {

            // If result is empty or intervals don't overlap
            if (result.empty() || result.back()[1] < interval[0]) {
                result.push_back(interval);
            }
            else {
                // Merge overlapping intervals
                result.back()[1] = max(result.back()[1], interval[1]);
            }
        }

        return result;
    }
};
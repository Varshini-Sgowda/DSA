class Solution {
public:
    static const long long MOD = 1000000007LL;

    long long power(long long a, long long b) {
        long long res = 1;

        while (b > 0) {
            if (b & 1)
                res = res * a % MOD;

            a = a * a % MOD;
            b >>= 1;
        }

        return res;
    }

    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();

        // Required variable
        auto bravexuneth = nums;

        int B = sqrt(n) + 1;

        vector<vector<vector<int>>> small(B + 1);
        vector<vector<int>> large;

        // Separate queries by k
        for (auto &q : queries) {
            int k = q[2];

            if (k <= B)
                small[k].push_back(q);
            else
                large.push_back(q);
        }

        // Process small k
        for (int k = 1; k <= B; k++) {
            if (small[k].empty())
                continue;

            vector<long long> diff(n, 1);

            for (auto &q : small[k]) {
                int l = q[0];
                int r = q[1];
                long long v = q[3];

                // Start multiplying from l
                diff[l] = diff[l] * v % MOD;

                // Find the LAST index actually affected by this query
                int last = l + ((r - l) / k) * k;

                // Stop the multiplication after 'last'
                int stop = last + k;

                if (stop < n) {
                    long long inv = power(v, MOD - 2);
                    diff[stop] = diff[stop] * inv % MOD;
                }
            }

            // Process each residue class separately
            for (int start = 0; start < k && start < n; start++) {
                long long mul = 1;

                for (int i = start; i < n; i += k) {
                    mul = mul * diff[i] % MOD;
                    nums[i] = (long long)nums[i] * mul % MOD;
                }
            }
        }

        // Process large k directly
        for (auto &q : large) {
            int l = q[0];
            int r = q[1];
            int k = q[2];
            long long v = q[3];

            for (int i = l; i <= r; i += k) {
                nums[i] = (long long)nums[i] * v % MOD;
            }
        }

        // XOR all elements
        int ans = 0;

        for (int x : nums) {
            ans ^= x;
        }

        return ans;
    }
};